class Solution {
public:
    int search(vector<int> &days,int val){
        
        for(int i=0;i<days.size();i++){
            if(val<=days[i]){
                return days[i];
            }
        }
        return 366;
    }
    int mincost(vector<int> &days,vector<int> &cost,vector<int> &memo,int indx){
        indx=search(days,indx);
        if(indx>days[days.size()-1]){
            return 0;
        }
        
        
        if(memo[indx]!=-1){
            return memo[indx];
        }
        return memo[indx]=min(min(cost[1]+mincost(days,cost,memo,indx+7),cost[2]+mincost(days,cost,memo,indx+30)),cost[0]+mincost(days,cost,memo,indx+1));
        
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(366,-1);
       
        return mincost(days,costs,memo,1);
    }
};