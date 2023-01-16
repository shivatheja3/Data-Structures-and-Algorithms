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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-101);
        ListNode *r=dummy;
        ListNode *p=list1;
        ListNode *q=list2;
        while(p&&q){
            if(p->val<q->val){
                r->next=p;
                r=r->next;
                ListNode *temp=p;
                p=p->next;
                temp->next=NULL;
            }
            else{
                r->next=q;
                r=r->next;
                ListNode *temp=q;
                q=q->next;
                temp->next=NULL;
            }
        }
        if(q!=NULL){
            r->next=q;
        }
        else if(p!=NULL){
            r->next=p;
        }
        dummy=dummy->next;
        return dummy;

    }
};