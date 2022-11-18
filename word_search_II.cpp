#include <iostream>
#include <vector>

using namespace std;

struct TrieNode{
    TrieNode* children[26] = {};
    string* word;

    void addWord(string& word){
        TrieNode* curr = this;
        for(char c : word){
            c -= 'a';
            if(curr->children[c] == nullptr) curr->children[c] = new TrieNode;
            curr = curr->children[c];
        }
        curr->word = &word;
    }
};

class Solution {
public:
    size_t m,n;
    vector<string> result;
    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* curr){
        if(r < 0 || r > m || c < 0 || c > n || board[r][c] == '.' || curr->children[board[r][c]-'a'] == nullptr) return;

        char visit = board[r][c];
        curr = curr->children[visit - 'a'];
        if(curr->word != nullptr){
            result.push_back(*curr->word);
            curr->word = nullptr;
        }
        board[r][c] = '.';
        for(int i = 0; i != 4; i++) dfs(board, r + dir[i][0], c + dir[i][1], curr);
        board[r][c] = visit;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty()) return {};

         m = board.size();
         n = board[0].size();

        TrieNode trieNode;
        for(auto word : words) trieNode.addWord(word);

        for(int i = 0; i != m; i++){
            for(int j = 0; j != n; j++){
                dfs(board, i, j, &trieNode);
            }
        }
        return result;
    }
};