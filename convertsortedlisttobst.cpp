/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* check(vector<int>& vec,int l,int r){
        if(l>r){
            return NULL;
        }
        int mid=(l+r)/2;
        TreeNode* t=new TreeNode(vec[mid]);
        t->left=check(vec,l,mid-1);
        t->right=check(vec,mid+1,r);
        return t;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>vec;
        while(head!=NULL){
            vec.push_back(head->val);
            head=head->next;
        }
        int e=vec.size()-1;
        TreeNode* root=check(vec,0,e);
        return root;
    }
};