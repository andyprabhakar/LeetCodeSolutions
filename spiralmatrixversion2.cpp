class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> matrix(n,vector<int>(n,0));
       if(n==1){
           matrix[0][0]=1;
           return matrix;
       }
       if(n==2){
           matrix[0][0]=1;
           matrix[0][1]=2;
           matrix[1][1]=3;
           matrix[1][0]=4;
           return matrix;
       }
       else {
           int x;
           if(n%2==1){
               x=n/2;
           }
           else{
               x=n/2-1;
           }
           int v=1;
           int temp;
           int chemp;
           int demp;
           for(int i=0;i<=x;i++){
               printf("yipee\n");
               for(int j=i;j<n-i;j++){
                   matrix[i][j]=v;
                   printf("%d",matrix[i][j]);
                   v++;
                   temp=j;
               }
               printf("\n");
               /*if(v==n*n){
                   break;
               }*/
               for(int k=i+1;k<n-i;k++){
                   matrix[k][temp]=v;
                   v++;
                   printf("%d",matrix[k][temp]);
                   demp=k;
               }
               printf("\n");
               for(int g=n-i-2;g>=i;g--){
                   matrix[demp][g]=v;
                   printf("%d",matrix[demp][g]);
                   v++;
                   chemp=g;
               }
               printf("\n");
               for(int h=demp-1;h>=i+1;h--){
                   matrix[h][chemp]=v;
                   printf("%d\n",matrix[h][demp]);
                   v++;
                   printf("%d",v);
               }
               
           }
           return matrix;
       }
    }
};