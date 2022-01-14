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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode *p=head;
        while(p){
            size++;
            p=p->next; 
        }
        
        ListNode *prev=NULL,*curr=head,*next=head->next;
        for(int i=0;i<size-n && curr!=NULL;i++){
            prev=curr;
            curr=next;
            next=curr->next;
        }
        
       
        if(prev==NULL && next==NULL){
            return NULL;
        }
        else if (prev!=NULL && next==NULL){
            prev->next=NULL;
        }
        else if(prev==NULL && next!=NULL){
            head=head->next;
        }
        else{
            prev->next=next;
        }
        return head;
    }
};