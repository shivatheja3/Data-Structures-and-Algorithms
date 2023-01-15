class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> res;
        int n=nums.size();
        for(int i=0;i<n;++i){
            while(d.size()>0&&nums[d.back()]<nums[i]){
                d.pop_back();
            }
            d.push_back(i);
            if(d.front()==(i-k)){
                d.pop_front();
            }
            if(i>=(k-1)){
                // cout<<nums[d.back
                res.push_back(nums[d.front()]);
            }
            
        }
        return res;
    }
};