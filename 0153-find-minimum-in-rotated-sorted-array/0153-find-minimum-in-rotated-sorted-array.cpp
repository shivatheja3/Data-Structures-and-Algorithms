class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0]<=nums[nums.size()-1]) return nums[0];
        int l=0,r=nums.size()-1;
        int m=(l+r)/2;
        while(l<=r){
            m=(l+r)/2;
            if(nums[l]<=nums[r]){
                return nums[l];
            }
            else if(nums[l]<=nums[m]&&nums[m]>nums[r]){
                l=m+1;
                
            }
            else
                r=m;
        }
        return r;
    }
};           
