class Solution {
public:
    int func(int n,int i,vector<int> &dp){
        if(i==n)
            return 1;
        if(i>n)
            return 0;
        if(dp[i]!=-1){
            return dp[i]; 
        }
        int a=0;
        if(i+1<=n)
            a=dp[i+1];
        int b=0;
        if(i+2<=n){
            b=dp[i+2];
        }
        // if(i+1<=n&&dp[i+1]==-1)
            a=func(n,i+1,dp);
        // if(i+2<=n&&dp[i+2]==-1)
            b=func(n,i+2,dp);
        dp[i]=a+b;
        return dp[i];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return func(n,0,dp);
    }
};