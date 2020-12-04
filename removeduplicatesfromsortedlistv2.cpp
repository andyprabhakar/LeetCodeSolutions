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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        vector<ListNode*>vec;
        ListNode* node=head;
        while(node!=NULL){
            vec.push_back(node);
            node=node->next;
        }
        if(vec.size()==0){
            return NULL;
        }
        node=head;
        vector<int>res;
        for(int j=1;j<vec.size();j++){
            if(vec[j]->val!=node->val){
                node->next=vec[j];
                node=node->next;
                
            }
            else{
               if(res.size()>0 && vec[j]->val!=res[res.size()-1]){
               res.push_back(vec[j]->val);
               }
                else if(res.size()==0){
                    res.push_back(vec[j]->val);
                }
                }
            }
        
        node->next=NULL;
        node=head;
        if(res.size()==0){
            return head;
        }
        int c=0;
        vector<int> temp;
        printf("%d\n",res.size());
        while( node!=NULL){
            if(node->val!=res[c]){
                temp.push_back(node->val);
            }
            if(c<res.size()-1 && node->val==res[c]){
                c++;
            }
            node=node->next;
        }
        node=head;
        if(temp.size()==0){
            return NULL;
        }
        printf("%d\n",temp.size());
        printf("ready\n");
        for(int j=0;j<temp.size();j++){
            node->val=temp[j];
            if(j<temp.size()-1){
            node=node->next;
            }
            else{
                node->next=NULL;
                node=node->next;
            }
            
        }
        //node->next=NULL;
        return head;
        
        }
};