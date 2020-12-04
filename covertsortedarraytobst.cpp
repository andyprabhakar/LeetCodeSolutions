/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*void sa(vector<int> &nums,int s,int e,TreeNode* root){
        if(s==e){
            root->val=nums[s];
            return;
        }
        int mid=(s+e)/2;
        root->val=nums[mid];
        root->left=new TreeNode(0);
        sa(nums,s,mid-1,root->left);
        
        root->right=new TreeNode(0);
        sa(nums,mid+1,e,root->right);
    }*/
    TreeNode* check(vector<int>& nums,int l,int r)
    {
        if(l>r)
            return NULL;
        int m=(l+r)/2;
        TreeNode* t=new TreeNode(nums[m]);
        t->left=check(nums,l,m-1);
        t->right=check(nums,m+1,r);
        return t;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      int n=nums.size();
      if(n==0){
          return NULL;
      }
      else{
      int s=0;
      int e=n-1;
      TreeNode* root=check(nums,s,e);
      return root;
      }
     
    }
};