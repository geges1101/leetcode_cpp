class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len=nums.size(), count=0;
        vector<int> pre;

        pre.push_back(0);
        for(int i=0;i<len;i++)
            pre.push_back(pre.back() + nums[i]);
        for(int i=0; i < pre.size(); i++){
            for(int j=i+1; j < pre.size(); j++){
                if(pre[j] - pre[i] == k)
                    count++;
            }
        }
        return count;
    }
};