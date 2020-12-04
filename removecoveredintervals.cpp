class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> vec;
        vector<int> res;
        for(int i=0;i<n;i++){
            if(i!=0){
                int j=0;
                while(j<vec.size()){
                if(vec[j]>=intervals[i][0] && res[j]<=intervals[i][1]){
                    vec.erase(vec.begin()+j);
                    res.erase(res.begin()+j);
                }
                else{
                    j++;
                }
            }
            }
            int j=0;
            int flag=0;
            while(j<vec.size()){
                if(intervals[i][0]>=vec[j] && intervals[i][1]<=res[j]){
                    flag=1;
                }
                j++;
            }
            if(flag==0){
            vec.push_back(intervals[i][0]);
            res.push_back(intervals[i][1]);
            }
        }
        return vec.size();
    }
};