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
    ListNode* mergeSort(ListNode* l1, ListNode* l2){
        ListNode* dummy=new ListNode(-1);
        ListNode* tmp=dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                tmp->next=l1;
                l1=l1->next;
            }
            else{
                tmp->next=l2;
                l2=l2->next;
            }
            tmp=tmp->next;
        }
        if(l1!=NULL && tmp!=NULL){
            tmp->next=l1;
            l1=l1->next;
        }
        if(l2!=NULL && tmp!=NULL){
            tmp->next=l2;
            l2=l2->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);
        return mergeSort(left, right);
    }
};