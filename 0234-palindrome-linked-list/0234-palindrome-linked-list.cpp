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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *p=head;
        // while(p){
        //     cout<<p->val<<" ";
        //     p=p->next;
        // }
        // cout<<endl;
        p=head;
        ListNode *q=p->next;
        ListNode *t=NULL;
        while(q){
            p->next=t;
            t=p;
            p=q;
            q=q->next;
        }
        p->next=t;
        head=p;
        // cout<<"g: "<<t->val<<endl;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        // find middle
        ListNode *p=head;
        ListNode *q=head;
        ListNode *prev=head;
        while(q&&q->next){
            prev=p;
            p=p->next;
            q=q->next->next;
        }
        //detach second half
        prev->next=NULL;
        //reverse second half
        if(q){
            ListNode *temp=p->next;
            p->next=NULL;
            p=temp;
        }
        ListNode *temp=reverseList(p);
        // cout<<temp->val<<endl;
        //start comparison
        q=head;
        // while(q){
        //     cout<<q->val<<" ";
        //     q=q->next;
        // }
        // cout<<endl;
        // while(temp){
        //     cout<<temp->val<<" ";
        //     temp=temp->next;
        // }
        cout<<endl;
        while(q&&temp){
            cout<<q->val<<" "<<temp->val<<endl;
            if(q->val!=temp->val){
                return false;
            }
            temp=temp->next;
            q=q->next;
        }
        return true;
    }
};