/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return head;
        }
        stack<Node*>s;
        Node* curr=head,*tail=head;
        while(curr!=NULL){
            if(curr->child!=NULL){
                if(curr->next!=NULL){s.push(curr->next);
                curr->next->prev=NULL;}
                curr->next=curr->child;
                curr->child->prev=curr;
                curr->child=NULL;
            }
            tail=curr;
            curr=curr->next;
        }
        while(!s.empty()){
                Node* new_node=s.top();
                curr=new_node;
                tail->next=curr;
                curr->prev=tail;
                while(curr!=NULL){
                    tail=curr;
                    curr=curr->next;
                }
                s.pop();
            }

        return head;
        
        
    }
};