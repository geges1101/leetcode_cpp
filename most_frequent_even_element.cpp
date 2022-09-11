#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i = 0; i != nums.size(); i++){
            if(nums[i] % 2 == 0) map[nums[i]]++;
        }
        if(map.empty()) return -1;

        int max = 0;
        for(auto i : map){
            if(i.second > max) max = i.second;
        }

        int min = INT_MAX;
        for(auto i : map){
            if(i.second == max && i.first < min) min = i.first;
        }

        return min;
    }
};
