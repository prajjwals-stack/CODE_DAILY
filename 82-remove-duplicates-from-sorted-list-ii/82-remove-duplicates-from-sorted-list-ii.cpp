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
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* itr=dummy, *curr=head->next;
        itr->next=head;
        
        while(curr){
            bool flag=false;
            while(curr && itr->next->val==curr->val){
                flag=true;
                curr=curr->next;
            }
            if(flag==true)itr->next=curr;
            else itr=itr->next;
            
            
            if(curr!=NULL)curr=curr->next;
            
        }
        return dummy->next;
    }
};