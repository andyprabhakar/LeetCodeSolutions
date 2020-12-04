/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  bool ispresent(TreeNode* node,int B){
     if(node==NULL)
     {
         return false;
     }
     if(node->val==B){
         return true;
     }
     return ispresent(node->left,B) || ispresent(node->right,B);
 }
 
 void inorder(TreeNode* node,int B,vector<int> &pathb){
     if(node==NULL){
         //pathb.clear();
         return;
     }
     if(node->val==B){
         pathb.push_back(node->val);
         return;
     }
    /* if(node->val==C){
         pathc.push_back(node->val);
         return;
     }*/
     pathb.push_back(node->val);
     //vector<int>temp=pathb;
     if(ispresent(node->left,B)==true){
     inorder(node->left,B,pathb);
     }
     //pathb.pop_back();
     //pathc.push_back(node->val);
     else if(ispresent(node->right,B)==true){
     inorder(node->right,B,pathb);
     }
     else{
         pathb.clear();
         return;
     }
 }

int Solution::lca(TreeNode* A, int B, int C) {
    vector<int>pathb;
    vector<int>pathc;
    TreeNode* node=A;
    TreeNode* ode=A;
    /*if(ispresent(node,B)==false || ispresent(ode,C)==false){
        return -1;
    }*/
    node=A;
    ode=A;
    inorder(node,B,pathb);
    inorder(ode,C,pathc);
   /* for(int j=0;j<pathb.size();j++){
        printf("%d,",pathb[j]);
    }
    printf("\n");
    for(int j=0;j<pathc.size();j++){
        printf("%d,",pathc[j]);
    }*/
    
    if(pathb.size()==0 || pathc.size()==0){
        return -1;
    }
    for(int i=1;i<min(pathb.size(),pathc.size());i++){
        if(pathb[i]!=pathc[i]){
            //return pathb[i-1];
            //printf("%d\n",i);
            return pathc.size()+pathb.size()-2*i;
            
        }
    }
    if(pathb.size()<pathc.size()){
        return pathc.size()-pathb.size();
    }
    else{
        return pathb.size()-pathc.size();
    }
    
}
