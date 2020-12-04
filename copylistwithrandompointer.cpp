/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
       Node* ode=new Node(0);
       Node* odehead=ode;
        Node* node=head;
        vector<Node*>vec;
        vector<Node*>res;
       while(node!=NULL){
           ode->val=node->val;
           ode->random=node->random;
           if(node->next!=NULL){
               Node* temp=new Node(0);
               ode->next=temp;
           }
           else{
              ode->next=NULL; 
           }
           
           node=node->next;
           ode=ode->next;
           
       }
        ode=odehead;
        node=head;
        while(node!=NULL){
            vec.push_back(node);
            res.push_back(ode);
            node=node->next;
            ode=ode->next;
        }
        ode=odehead;
        node=head;
        while(node!=NULL){
            int c;
            for(int i=0;i<vec.size();i++){
                if(vec[i]==node->random){
                    c=i;
                }
            }
            if(node->random!=NULL){
            ode->random=res[c];
            }
            else{
                ode->random=NULL;
            }
            node=node->next;
            ode=ode->next;
        }
        return odehead;
    }
};