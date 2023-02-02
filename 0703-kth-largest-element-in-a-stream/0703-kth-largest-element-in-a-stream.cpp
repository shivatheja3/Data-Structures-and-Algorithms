class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int> > pq;
    int k1;
    KthLargest(int k, vector<int>& nums) {
        // int k1=k;
        // vector<int> t=nums;
        k1=k;
        for(int i=0;i<nums.size();++i){
            pq.push(nums[i]);
            if(i>=k1){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        
        pq.push(val);
        // pq.pop();
        if(pq.size()>k1) pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */