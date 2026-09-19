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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        while(prev->next!=NULL && prev->next->next!=NULL){
            ListNode* f=prev->next;
            ListNode* s=f->next;
            f->next=s->next;
            s->next=f;
            prev->next=s;
            prev=f;
        }
        return dummy->next;
    }
};