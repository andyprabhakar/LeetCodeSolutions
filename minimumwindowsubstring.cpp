class Solution {
public:
    bool hashmap(vector<int> &mps,vector<int> &mpt){
        for(int i=0;i<256;i++){
            if(mps[i]<mpt[i]){
                return false;
            }
           
            
        }
        
        return true;
    }
    string minWindow(string s, string t) {
        vector<int>mps(256,0);
        vector<int>mpt(256,0);
        int n=s.size();
        int m=t.size();
        /*for(int i=0;i<n;i++){
            mps[s[i]]++;
        }*/
        for(int i=0;i<m;i++){
            mpt[t[i]]++;
        }
        //cout<<mps['B']<<endl;
        string ans;
        int st=0;
        int e=0;
        //mps[s[e]]++;
        //int flag=0;
        int k=INT_MAX;
        while(e<n){
            mps[s[e]]++;
            e++;
            while(hashmap(mps,mpt)==true && st<e){
               if(e-st+1<k){
                   k=e-st+1;
                   ans=s.substr(st,e-st);
               }
               mps[s[st]]--;
               st++;
                
            }
            
        }
        
        
        return ans;
    }
};