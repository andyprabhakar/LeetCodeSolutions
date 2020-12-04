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
    void levelorder(queue<TreeNode*>q,vector<vector<int>>& vec){
        if(q.size()==0){
            //res.push_back(make_pair(indx,NULL));
            return;
        }
        int s=q.size();
        vector<int> temp;
        for(int j=0;j<s;j++){
        temp.push_back(q.front()->val);
        
        if(q.front()->left!=NULL){
            q.push(q.front()->left);
            
        }
        if(q.front()->right!=NULL){
            q.push(q.front()->right);
        }
        q.pop();
        }
        vec.push_back(temp);
        levelorder(q,vec);
    
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        queue<TreeNode*>q;
        if(root==NULL){
            return {};
        }
        q.push(root);
        levelorder(q,vec);
        return vec;
    }
};