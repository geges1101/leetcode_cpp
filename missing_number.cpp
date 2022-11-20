class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i != n; i++){
            if(count != nums[i]) return nums[i] -1;
            count++;
        }
        return n;
    }
};