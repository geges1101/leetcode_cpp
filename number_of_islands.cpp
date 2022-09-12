#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        vector<vector<int>> route = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
        queue<pair<int,int>> q;
        int m = int(grid.size());
        int n = int(grid[0].size());
        int res = 0;

        for(int i = 0; i != m; i++){
            for(int j = 0; j != n; j++){
                if(grid[i][j] == '1'){
                    res++;
                    q.push(make_pair(i,j));

                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        if(grid[x][y] == '1'){
                            grid[x][y] = '0';
                            for(auto path : route){
                                int next_x = x + path[0];
                                int next_y = y + path[1];
                                if(next_x >= 0 && next_x < m &&
                                   next_y >= 0 && next_y < n)
                                    q.emplace(make_pair(next_x, next_y));
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};