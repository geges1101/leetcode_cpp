#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(board[i][j] == word[0] && traverse(board, word, i, j, 0))
                    return true;

        return false;
    }

    bool traverse(vector<vector<char>>& board, string word, int i, int j, int count) {
        if(count == word.size()) return true;

        if(i < 0 ||
        i >= board.size() ||
        j < 0 ||
        j >= board[i].size() ||
        board[i][j] != word[count]) return false;

        board[i][j] = '0';

        bool curr = traverse(board, word, i, j - 1, count + 1) ||
                    traverse(board, word, i - 1, j, count + 1) ||
                    traverse(board, word, i, j + 1, count + 1) ||
                    traverse(board, word, i + 1, j, count + 1);

        board[i][j] = word[count];

        return curr;
    }
};