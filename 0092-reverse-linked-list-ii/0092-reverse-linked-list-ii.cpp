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
    ListNode *merge(vector<ListNode *> &v){
        ListNode *dummy=new ListNode(5);
        ListNode *prev=dummy;
        for(int i=0;i<v.size();++i){
            // cout<<v[i]->val<<endl;
            prev->next=v[i];
            ListNode *t=v[i];
            // ListNode *prev=NULL;
            while(t){
                prev=t;
                // cout<<prev->val<<endl;
                // cout<<t->val<<endl;
                t=t->next;
            }
        }
        return dummy->next;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        int c=0;
        vector<ListNode *> v;
        if(left==1){
            ListNode *p=head;
            v.push_back(p);
            while(p){
                c++;
                if(c==right){
                    // ListNode *temp=p->next;
                    v.push_back(p->next);
                    p->next=NULL;
                    break;
                }
                p=p->next;
            }
            v[0]=reverseList(v[0]);
            // for(int i=0;i<v.size();++i){
            //     cout<<v[i]->val<<endl;
            // }
            return merge(v);
        }
        v.push_back(head);
        ListNode *p=head;
        ListNode *prev=NULL;
        while(p){
            c++;
            if(c==left){
                v.push_back(p);
                prev->next=NULL;
            }
            if(c==right){
                v.push_back(p->next);
                p->next=NULL;
                break;
            }
            prev=p;
            p=p->next;
        }
        v[1]=reverseList(v[1]);
        return merge(v);    
    }
};