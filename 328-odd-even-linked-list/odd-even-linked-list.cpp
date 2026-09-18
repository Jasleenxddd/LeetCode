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
        if(head==NULL || head->next==NULL) return head;
        ListNode* odd_index=head;
        ListNode* even_index=head->next;
        ListNode* even_head=head->next;
        while(even_index!=NULL && even_index->next!=NULL){
            odd_index->next=even_index->next;
            odd_index=odd_index->next;
            even_index->next=odd_index->next;
            even_index=even_index->next;
        }
        odd_index->next=even_head;
        return head;
    }
};