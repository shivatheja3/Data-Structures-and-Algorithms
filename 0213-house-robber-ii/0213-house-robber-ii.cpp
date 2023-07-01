class Solution {
public:
    int f(vector<int> &nums,int n,int ind,vector<int> &dp){
        if(ind>=n)  return 0;
        if(dp[ind]!=-1) return dp[ind];
        // cout<<ind<<endl;
        int a=f(nums,n,ind+1,dp);
        int b=nums[ind]+f(nums,n,ind+2,dp);
        dp[ind]=max(a,b);
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        vector<int> dp1(nums.size(),-1),dp2(nums.size(),-1);
        return max(f(nums,nums.size()-1,0,dp1),f(nums,nums.size(),1,dp2));
    }
};