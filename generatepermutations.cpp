class Solution {
public:
    void permutations(vector<int> &nums,vector<vector<int>>&ans,vector<int>&vec,int n,vector<int> &occ,int indx){
        if(occ.size()==n){
            ans.push_back(vec);
            return;
        }
        for(int i=0;i<nums.size();i++){
            int flag=0;
            for(int j=0;j<occ.size();j++){
                if (i==occ[j]){
                flag=1;
                }
            }
            if(flag==0){
                vec[i]=nums[indx];
                occ.push_back(i);
                permutations(nums,ans,vec,n,occ,indx+1);
                occ.pop_back();
            }
            //occ.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>vec(nums.size(),0);
        int n=nums.size();
        vector<int>occ;
        permutations(nums,ans,vec,n,occ,0);
        return ans;
    }
};