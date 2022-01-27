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
    int pairSum(ListNode* head) {
        ListNode* slow=head, *prev=NULL;
        ListNode* fast=head;
        while(fast!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        int maxi=0;
        stack<int>s;
        while(slow){
            s.push(slow->val);
            slow=slow->next;
        }
        ListNode *p=head;
        while(s.empty()==false){
            int sum=p->val+s.top();
            maxi=max(maxi,sum);
            p=p->next;
            s.pop();
        }
        return maxi;
        
        
    }
};