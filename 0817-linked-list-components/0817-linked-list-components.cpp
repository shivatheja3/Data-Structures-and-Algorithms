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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int> h1;
        for(int i=0;i<nums.size();++i){
            h1[nums[i]]++;
        }
        ListNode *p=head;
        int c=0;
        int m=0;
        while(p){
            if(h1[p->val]==0){
                // --c;
                m=0;
            }
            else if(m==0&&h1[p->val]==1){
                m=1;
                c++;
            }
            p=p->next;
        }
        // if(m==0) return c+1;
        return c;
    }
};