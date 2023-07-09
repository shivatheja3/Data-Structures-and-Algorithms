class Solution {
public:
    int f(int ind,vector<int>& nums, int target,vector<int> &dp){
        if(ind==(nums.size()-1)){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int a=INT_MIN;
        for(int i=(ind+1);i<nums.size();++i){
            int x=nums[i]-nums[ind];
            if(x<=target&&x>=-target){
                a=max(a,1+f(i,nums,target,dp));
            }
        }
        return dp[ind]=a;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        int x=f(0,nums,target,dp);
        return x>0?x:-1;
    }
};