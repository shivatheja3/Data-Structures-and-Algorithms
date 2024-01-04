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
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        vector<ListNode *> h;
        int c=0;
        ListNode *temp=head;
        ListNode *t1=head;
        while(temp){
            c++;
            if(c==k){
                c=0;
                h.push_back(t1);
                t1=temp->next;
                temp->next=NULL;
                temp=t1;
                continue;
            }
            temp=temp->next;
        }
        ListNode *t2=NULL;
        if(c!=0){
            t2=t1;
            // h.push_back(t1);
        }
        temp=NULL;
        for(int i=0;i<h.size();++i)
            h[i]=reverseList(h[i]);
        head=h[0];
        temp=h[0];
        ListNode *prev=NULL;
        while(temp){
            prev=temp;
            temp=temp->next;
        }
        for(int i=1;i<h.size();++i){
            prev->next=h[i];
            temp=h[i];
            while(temp){
                prev=temp;
                temp=temp->next;
            }
        }
        prev->next=t2;
        return head;
    }
};