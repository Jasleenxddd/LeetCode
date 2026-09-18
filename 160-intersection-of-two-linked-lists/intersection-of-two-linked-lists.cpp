/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB== NULL) return NULL;
        ListNode* tmpA=headA;
        ListNode* tmpB=headB;
        while(tmpA!=tmpB){
            tmpA=tmpA->next;
            tmpB=tmpB->next;
            if(tmpA==tmpB) return tmpA;
            if(tmpA==NULL) tmpA=headB;
            if(tmpB==NULL) tmpB=headA;
        }
        return tmpA;
    }
};