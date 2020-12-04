class Solution {
public:
    int getmax(vector<int>& vec,int pos){
        if(pos==0){
            return INT_MIN;
        }
        else{
            return vec[pos-1];
        }
    }
    int getmin(vector<int> &vec,int pos){
        if(pos==vec.size()){
            return INT_MAX;
        }
        else{
            return vec[pos];
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m){
            vector<int>temp;
            temp=nums2;
            nums2=nums1;
            nums1=temp;
        }
        int s=0;
        int e=nums1.size();
        while(s<=e){
            int px=(s+e)/2;
            int py=(n+m+1)/2-px;
            int lx=getmax(nums1,px);
            int rx=getmin(nums1,px);
            int ly=getmax(nums2,py);
            int ry=getmin(nums2,py);
            if(lx<=ry && ly<=rx){
                if((n+m)%2==0){
                    return (max(lx,ly)+min(rx,ry))/2.0;
                }
                else{
                    return max(lx,ly);
                }
            }
            else if(lx>ry){
                e=px-1;
            }
            else{
                s=px+1;
            }
            
        }
        return -1;
    }
};
//I have never come across any such form of binary search...
//Nothing but bamboozled..