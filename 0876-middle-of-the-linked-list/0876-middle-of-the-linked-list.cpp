class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p=head,*q=head;
        while(q&&q->next){
            p=p->next;
            q=q->next->next;
            // if(q){
            //     q=q->next;
            // }
        }
        return p;
    }
};