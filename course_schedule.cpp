#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool dfs(int curr,unordered_map<int, vector<int>>& to, unordered_set<int>& visited){
        if(visited.count(curr)) return false;
        if(to.empty()) return true;

        visited.insert(curr);
        for(auto leaf : to[curr])
            if(!dfs(leaf, to, visited)) return false;

        visited.erase(visited.find(curr));
        to[curr] = vector<int>();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> toVisit;
        unordered_set<int> visited;

        for(auto item : prerequisites){
            toVisit[item[1]].push_back(item[0]);
        }

        for(int i = 0; i != numCourses; i++){
            if(!dfs(i, toVisit, visited)) return false;
        }

        return true;
    }
};