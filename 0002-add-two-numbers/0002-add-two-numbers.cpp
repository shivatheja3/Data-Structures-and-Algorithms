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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1=l1;
        ListNode *p2=l2;
        int carry=(p1->val+p2->val)/10;
        ListNode *res=new ListNode((p1->val+p2->val)%10);
        // cout<<res->val<<" "<<carry<<endl;
        p1=p1->next;
        p2=p2->next;
        ListNode *r=res;
        while(p1&&p2){
            int x=(p1->val+p2->val+carry)%10;
            ListNode *temp=new ListNode(x);
            r->next=temp;
            r=r->next;
            carry=(p1->val+p2->val+carry)/10;
            p1=p1->next;
            p2=p2->next;
        }
        if(p1){
            while(p1){
            int x=(p1->val+carry)%10;
            ListNode *temp=new ListNode(x);
            r->next=temp;
            r=r->next;
            carry=(p1->val+carry)/10;
            p1=p1->next;
        }
            if(carry>0){
                ListNode *temp=new ListNode(carry);
                r->next=temp;
            }
        }
        else if(p2){
           while(p2){
            int x=(p2->val+carry)%10;
            ListNode *temp=new ListNode(x);
            r->next=temp;
            r=r->next;
            carry=(p2->val+carry)/10;
            p2=p2->next;
        }
            if(carry>0){
                ListNode *temp=new ListNode(carry);
                r->next=temp;
            } 
        }else if(carry>0){
            ListNode *temp=new ListNode(carry);
                r->next=temp;
        }
        return res;
    }
};