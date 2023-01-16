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
        ListNode *dummy=new ListNode(10000);
        dummy->next=head;
        ListNode *p=dummy;
        while(p->next){
            int x=p->next->val;
            ListNode *q=p->next;
            int c=0;
            while(q){
                if(q->val==x){
                    ++c;
                }
                else{
                    break;
                }
                q=q->next;
            }
            cout<<x<<" "<<c<<endl;
            if(c>1){
                p->next=q;
            }
            else{
                p=p->next;
            }
        }
        head=dummy;
        head=head->next;
        // cout<<dummy->val<<" "<<dummy->next->val;
        return head;
    }
};