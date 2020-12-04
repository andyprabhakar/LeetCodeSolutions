class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>vec;
        vec.push_back(-1);
        vec.push_back(-1);
        int s=0;
        int e=nums.size()-1;
        int res=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                res=mid;
                s=e+1;
            }
            else if(nums[mid]>target){
                e--;
            }
            else{
                s++;
            }
        }
        if(res==-1){
            return vec;
        }
        else{
            cout<<nums[res]<<endl;
            int x;
            int y;
            int rep=res;
            int flag;
            while(res-1>=0 &&nums[res-1]==target){
                s=0;
                e=res-1;
                flag=0;
                while(s<=e && flag==0){
                    int mid=(s+e)/2;
                    if(nums[mid]==target){
                        res=mid;
                        flag=1;
                    }
                    else if(nums[mid]<target){
                        s=mid+1;
                    }
                    else{
                        e=mid-1;
                    }
                }
            }
            x=res;
            res=rep;
            while(res+1<nums.size() && nums[res+1]==target){
                s=res+1;
                e=nums.size()-1;
                flag=0;
                while(s<=e && flag==0){
                    int mid=(s+e)/2;
                    if(nums[mid]==target){
                        res=mid;
                        flag=1;
                    }
                    else if(nums[mid]<target){
                        s=mid+1;
                    }
                    else{
                        e=mid-1;
                    }
                }
            }
            y=res;
            
            vec[1]=y;
            vec[0]=x;
            return vec;
        }
    }
};