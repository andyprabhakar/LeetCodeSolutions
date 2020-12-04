//looks like this problem requires dp;
class Solution {
public:
    int path(int indx1,int indx2,vector<int>& vec,vector<vector<int>> &memo,int x,int y,vector<vector<int>> &grid){
        if(indx1==x && indx2==y){
            int z=0;
            vec.push_back(grid[indx1][indx2]);
            for(int i=0;i<vec.size();i++){
                z+=vec[i];
            }
        
            return z;
        }
        else if(indx1>x || indx2>y){
            return INT_MAX;
        }
        if(memo[indx1][indx2]!=-1){
            return memo[indx1][indx2];
        }
        vec.push_back(grid[indx1][indx2]);
        vector<int> res=vec;
        memo[indx1][indx2]=std::min(path(indx1,indx2+1,vec,memo,x,y,grid),
        path(indx1+1,indx2,res,memo,x,y,grid));
        for(int k=0;k<vec.size();k++){
            printf("%d\n",vec[k]);
        }
        return memo[indx1][indx2];
        
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0){
            return 0;
        }
        else{
            int n=grid[0].size();
            for(int i=n-2;i>=0;i--){
                grid[m-1][i]=grid[m-1][i]+grid[m-1][i+1];
            }
            for(int i=m-2;i>=0;i--){
                grid[i][n-1]=grid[i][n-1]+grid[i+1][n-1];
            }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                grid[i][j]=grid[i][j]+std::min(grid[i+1][j],grid[i][j+1]);
            }
            //grid[i][n-1]=grid[i][n-1]+grid[i+1][n-1];
        }
        
            /*for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    printf("%d\n",grid[i][j]);
                }
            }*/
            return grid[0][0];
        
        }
        
    }
};