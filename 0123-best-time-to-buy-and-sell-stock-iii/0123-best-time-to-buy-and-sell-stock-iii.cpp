class Solution {
public:
    int f(vector<int>& prices,vector<vector<vector<int>>> &dp,int buy,int ind,int total){
        if(ind==prices.size()||total==2)
            return 0;
        if(dp[ind][buy][total]!=-1)
            return dp[ind][buy][total];
        int profit=0;
        if(buy==1)
            profit=max(-prices[ind]+f(prices,dp,0,ind+1,total),f(prices,dp,1,ind+1,total));
        else
            profit=max(prices[ind]+f(prices,dp,1,ind+1,total+1),f(prices,dp,0,ind+1,total));
        return dp[ind][buy][total]=profit;
    }
    int maxProfit(vector<int>& prices) {
        // int dp[prices.size()+1][2];
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        int total=0;
        return f(prices,dp,1,0,total);
    }
};