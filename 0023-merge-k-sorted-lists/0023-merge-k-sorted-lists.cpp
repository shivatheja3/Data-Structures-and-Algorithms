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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
        pair<int,pair<ListNode *,int>>,
        vector<pair<int,pair<ListNode *,int>>>,
        greater<pair<int,pair<ListNode *,int>>>
        > minheap;
        ListNode *dummy=new ListNode(10);
        ListNode *p=dummy;
        for(int i=0;i<lists.size();++i){
            if(lists[i]){
                minheap.push({lists[i]->val,{lists[i],i}});
            }
        }
        while(!minheap.empty()){
            ListNode *temp=new ListNode(minheap.top().first);
            p->next=temp;
            p=temp;
            int ind=minheap.top().second.second;
            ListNode *t=minheap.top().second.first->next;
            minheap.pop();
            if(t){
                minheap.push({t->val,{t,ind}});
            }
        }
        return dummy->next;
    }
};