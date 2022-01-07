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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL ||head->next->next==NULL)return head;
        ListNode* odd=head,*even=head->next,*even_head=head->next;
        while(odd->next && even->next){
            odd->next=even->next;
            even->next=odd->next->next;
            
            odd=odd->next;
            even=even->next;
        }
        odd->next=even_head;
    
        return head;
        
        
    }
};