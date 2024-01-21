class Solution {
public:
    int f(vector<int> &nums,int ind,vector<int> &dp){
        if(ind>=nums.size())  return 0;
        if(dp[ind]!=-1) return dp[ind];
        int a=f(nums,ind+1,dp);
        int b=nums[ind]+f(nums,ind+2,dp);
        dp[ind]=max(a,b);
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums,0,dp);
    }
};