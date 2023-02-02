class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int i=0;
        priority_queue <int, vector<int>, greater<int> > pq;
        for(i=0;i<nums.size();++i){
            pq.push(nums[i]);
            if(i>=k){
                pq.pop();
            }
        }
        
        return pq.top();
    }
};