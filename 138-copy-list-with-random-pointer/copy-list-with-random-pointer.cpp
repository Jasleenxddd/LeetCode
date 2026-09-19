/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*, Node*> mpp;
        Node* tmp=head;
        while(tmp!=NULL){
            mpp[tmp]=new Node(tmp->val);
            tmp=tmp->next;
        }
        tmp=head;
        while(tmp!=NULL){
            mpp[tmp]->next=mpp[tmp->next];
            if(tmp->random!=NULL) mpp[tmp]->random=mpp[tmp->random];
            else mpp[tmp]->random=NULL;
            tmp=tmp->next;
        }
        return mpp[head];
    }
};