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
        ListNode *dOdd=new ListNode(1);
        ListNode *dEven=new ListNode(2);
        ListNode *p1=dOdd;
        ListNode *p2=dEven;
        ListNode *p=head;
        int c=1;
        while(p){
            if((c)&1==1){
                p1->next=p;
                ListNode *temp=p->next;
                p->next=NULL;
                p1=p1->next;
                p=temp;
            }
            else{
                p2->next=p;
                ListNode *temp=p->next;
                p->next=NULL;
                p2=p2->next;
                p=temp;
            }
            ++c;
        }
        p1->next=dEven->next;
        return dOdd->next;
    }
};