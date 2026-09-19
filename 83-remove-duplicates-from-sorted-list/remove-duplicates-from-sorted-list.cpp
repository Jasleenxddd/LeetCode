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
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* tmp=head;
        while(tmp!=NULL && tmp->next!=NULL){
            ListNode* front=tmp->next;
            if(tmp->val==front->val){
                tmp->next=front->next;
            }
            else tmp=tmp->next;
        }
        return dummy->next;
    }
};