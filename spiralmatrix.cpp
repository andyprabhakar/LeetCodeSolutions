class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0){
            return {};
        }
        int n=matrix[0].size();
        vector<int>vec;
        int temp;
        int demp;
        int chemp;
        int flag;
        int flag1;
        int flag2;
        int x;
        int p=std::min(m,n);
        if(p%2==1){
            x=p/2;
        }
        else{
            x=p/2-1;
        }
        if(n>=3){
        for(int i=0;i<=x;i++){
            printf("yipeee\n");
            for(int j=i;j<n-i;j++){
                vec.push_back(matrix[i][j]);
                temp=j;
            }
            flag=0;
            flag1=0;
            flag2=0;
            for(int k=i+1;k<m-i;k++){
                vec.push_back(matrix[k][temp]);
                demp=k;
                flag2=1;
            }
            if(flag2==1){
                flag1=0;
            for(int g=temp-1;g>=i;g--){
                vec.push_back(matrix[demp][g]);
                chemp=g;
                flag1=1;
            }
            }
            if(flag1==1){
            for(int o=demp-1;o>=i+1;o--){
                vec.push_back(matrix[o][chemp]);
            }
            }
        }
        return vec;
    }
        else if(n==2){
            for(int j=0;j<n;j++){
                vec.push_back(matrix[0][j]);
            }
            for(int r=1;r<m;r++){
                vec.push_back(matrix[r][n-1]);
            }
            //vec.push_back(matrix[m-1][0]);
            for(int r=m-1;r>=1;r--){
                vec.push_back(matrix[r][0]);
            }
            return vec;
        }
        else{
            for(int i=0;i<m;i++){
                vec.push_back(matrix[i][0]);
                
            }
            return vec;
        }
    }
};