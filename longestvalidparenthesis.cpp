class Solution {
public:
    
    int longestValidParentheses(string s) {
        
        int ans=0;
        int n=s.size();
        
        int st=0;
        int e=0;
        int ob=0;
        int cb=0;
        while(e<n){
            if(s[e]=='('){
                ob++;
                e++;
            }
            else if(s[e]==')'){
                cb++;
                e++;
            }
            if(cb>ob){
                while(ob!=cb){
                    if(s[st]=='('){
                        ob--;
                        st++;
                    }
                    else{
                        cb--;
                        st++;
                    }
                }
                if(ob==cb){
                    ans=max(ans,2*ob);
                }
            }
            else if(ob==cb){
                ans=max(ans,2*ob);
            }
        }
         st=n-1;
         e=n-1;
         ob=0;
         cb=0;
        while(e>=0){
            if(s[e]=='('){
                ob++;
                e--;
            }
            else if(s[e]==')'){
                cb++;
                e--;
            }
            if(ob>cb){
                while(ob!=cb){
                    if(s[st]=='('){
                        ob--;
                        st--;
                    }
                    else{
                        cb--;
                        st--;
                    }
                }
                if(ob==cb){
                    ans=max(ans,2*ob);
                }
            }
            else if(ob==cb){
                ans=max(ans,2*ob);
            }
        }
        return ans;
        
    }
};