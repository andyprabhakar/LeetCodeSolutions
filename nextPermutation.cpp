class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int temp;
        int flag=0;
        int mon=nums.size()-1;
          
          for(int j=nums.size()-2;j>=0;j--){
              if(nums[j+1]>nums[j]){
                  mon=j+1;
                  for(int k=j+1;k<nums.size();k++){
                      if(nums[k]>nums[j] && nums[k]<nums[mon]){
                          mon=k;
                      }
                  }
                  temp=nums[j];
                  nums[j]=nums[mon];
                  nums[mon]=temp;
                  flag=1;
                  sort(nums.begin()+j+1,nums.end());
                  break;
              }
          }
              if(flag==0){
                  sort(nums.begin(),nums.end());
              }
          }
          
        
    
};