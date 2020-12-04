class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ps=nums[0];
        int fs=nums[0];
        for(int i=1;i<nums.size();i++){
            ps=max(ps+nums[i],nums[i]);
            fs=max(ps,fs);
        }
        return fs;
    }
};