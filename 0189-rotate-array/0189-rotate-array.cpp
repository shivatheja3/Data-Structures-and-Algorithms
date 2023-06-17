class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // approach 1
        // shifting O((n-k)*k),O(1)
        // approach 2
        // copy last k elements into new vector
        // then append first n-k elements into new vector
        // approach 3
        // step 1: reverse entire array
        // step 2: reverse last k elements
        // step 3: reverse first (n-k) elements
        k%=nums.size();
        
        reverse(nums.begin()+(nums.size()-k),nums.end());
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.begin(),nums.end());
    }
};