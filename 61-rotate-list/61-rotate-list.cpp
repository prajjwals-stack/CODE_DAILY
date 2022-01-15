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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* p=head;
        int length=1;
        while(p->next!=NULL){
            length++;
            p=p->next;
        }
        p->next=head;
        k=k%length;
        ListNode *q=head;
        for(int i=1;i<length-k;i++){
            q=q->next;
        }
        head=q->next;
        q->next=NULL;
        
        return head;
    }
};