class Solution {
public:
    int f(vector<int>& prices,vector<vector<int>> &dp,int buy,int ind){
        if(ind==prices.size())
            return 0;
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        int profit=0;
        if(buy==1)
            profit=max(-prices[ind]+f(prices,dp,0,ind+1),f(prices,dp,1,ind+1));
        else
            profit=max(prices[ind]+f(prices,dp,1,ind+1),f(prices,dp,0,ind+1));
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        // int dp[prices.size()+1][2];
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(prices,dp,1,0);
    }
};