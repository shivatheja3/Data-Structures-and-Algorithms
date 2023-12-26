class Solution {
public:
    int f(vector<vector<int>> &dp,int n,int k,int target){
        if(target==0&&n==0) return 1;
        if(n==0||target<=0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int ans=0;
        for(int i=1;i<=k;++i){
            ans=(ans+f(dp,n-1,k,target-i))%((int)pow(10,9)+7);
        }
        return dp[n][target]=ans%((int)pow(10,9)+7);
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return f(dp,n,k,target);
    }
};