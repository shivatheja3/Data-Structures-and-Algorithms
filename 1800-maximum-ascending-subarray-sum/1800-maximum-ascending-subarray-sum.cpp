class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res=nums[0];
        int ans=nums[0];
        int prev=nums[0];
        for(int i=1;i<nums.size();++i){
            if(nums[i]>nums[i-1]){
                res+=nums[i];
                ans=max(ans,res);
            }
            else{
                // ans=nums[i];
                res=nums[i];
                ans=max(ans,res);
            }
        }
        return ans;
    }
};