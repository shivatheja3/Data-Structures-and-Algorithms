class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,0);
        dp[0]=cost[0];
        if(cost.size()>0)
            dp[1]=cost[1];
        for(int i=2;i<cost.size();++i){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        dp[cost.size()]=min(dp[cost.size()-1],dp[cost.size()-2]);
        return dp[cost.size()];
    }
};