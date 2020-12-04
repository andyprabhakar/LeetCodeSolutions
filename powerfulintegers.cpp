class Solution {
public:
    void comb(int x,int y,int bound,vector<int> &ans,int xpow,int ypow ){
        if(pow(x,xpow)+pow(y,ypow)>bound){
            return;
        }
        ans.push_back(pow(x,xpow)+pow(y,ypow));
        if(x>1){
        comb(x,y,bound,ans,xpow+1,ypow);
        }
        if(y>1){
        comb(x,y,bound,ans,xpow,ypow+1);
        }
        //comb(x,y,ans,xpow+1,ypow+1);
    }
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int>ans;
        int i=0;
        int j=0;
        comb(x,y,bound,ans,0,0);
        int k=1;
        sort(ans.begin(),ans.end());
        while(k<ans.size()){
            if(ans[k]==ans[k-1]){
                ans.erase(ans.begin()+k);
            }
            else{
                k++;
            }
        }
        return ans;
        
       
    }
};