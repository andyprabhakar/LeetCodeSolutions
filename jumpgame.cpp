bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        int i=0;
        int iprev=0;
        printf("%d\n",nums.size());
        while(i<nums.size()){
             if(i==nums.size()-1){
                    return true;
            }
            if(nums[i]>0){
                i=i+nums[i];
               // printf("%d\n",i);
               
            }
            else{
                int c=i;
                if(i==iprev){
                    return false;
                }
                iprev=i;
                printf("%d\n",i);
                printf("%d\n",nums[i]);
                while(nums[c]==0 || (c>0 &&nums[c]<=i-c)){
                    c--;
                }
                i=c;
                printf("%d\n",c);
                printf("%d\n",nums[c]);
                if(c==0 || c==iprev){
                    return false;
                }
                i=i+nums[c];
            }
        }
        return true;
    }