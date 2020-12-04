class Solution {
public:
    int editd(string word1,string word2,int i,int j,vector<vector<int>> &memo){
        if(i==word1.size() || j==word2.size()){
            if(i==word1.size()){
                return word2.size()-j;
            }
            else{
                return word1.size()-i;
            }
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        if(word1[i]!=word2[j]){
            return memo[i][j]=1+min(editd(word1,word2,i+1,j+1,memo),min(editd(word1,word2,i+1,j,memo),editd(word1,word2,i,j+1,memo)));
        }
        return memo[i][j]=editd(word1,word2,i+1,j+1,memo);
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size()+1,vector<int>(word2.size()+1,-1));
        return editd(word1,word2,0,0,memo);
    }
};