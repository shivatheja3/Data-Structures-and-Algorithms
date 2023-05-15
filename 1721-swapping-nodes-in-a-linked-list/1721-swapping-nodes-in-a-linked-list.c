/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapNodes(struct ListNode* head, int k){
    int count=0;
    struct ListNode *p,*q,*r=head;
    while(r){
        count++;
        r=r->next;
    }
    r=head;
    int c=0;
    while(r){
        c++;
        if(c==k){
            p=r;
        }
        if(c==count+1-k){
            q=r;
        }
        r=r->next;
    }
    printf("%d %d %d\n",p->val,q->val,count);
    count=p->val;
    p->val=q->val;
    q->val=count;
    return head;
}