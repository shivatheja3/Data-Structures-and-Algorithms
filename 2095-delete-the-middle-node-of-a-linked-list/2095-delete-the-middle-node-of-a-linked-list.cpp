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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL){
            return head;
        }
        else if(head->next==NULL){
            return NULL;
        }
        else if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        ListNode *p=head;
        ListNode *q=head;
        ListNode *r=p;
        while(q){
            if(q->next){
            r=p;
            p=p->next;
            q=q->next->next; 
            }
            else{
                break;
            }
        }
        cout<<p->val<<" "<<r->val;
        r->next=r->next->next;
        return head;
    }
};