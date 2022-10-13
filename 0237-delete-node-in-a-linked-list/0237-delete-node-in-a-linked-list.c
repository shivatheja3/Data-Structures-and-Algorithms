/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *p=node;
    struct ListNode *q=p->next;
    int temp=p->val;
    p->val=q->val;
    q->val=temp;
    p->next=q->next;
}