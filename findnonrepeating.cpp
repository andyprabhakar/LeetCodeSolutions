
public:
    int singleNumber(vector<int>& nums) {
        int flag=0;
        //sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            flag^=nums[i];
        }
        return flag;
    }
};
