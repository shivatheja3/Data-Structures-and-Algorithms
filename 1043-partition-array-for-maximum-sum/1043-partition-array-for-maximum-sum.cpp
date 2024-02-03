class Solution {
public:
    int func(vector<int>& arr, int k,vector<int>& dp, int i){
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int m1=0,m2=0;
        for(int j=i;j<arr.size()&&j<(i+k);++j){
            m1=max(m1,arr[j]);
            m2=max(m2,m1*(j-i+1)+func(arr,k,dp,j+1));
        }
        return dp[i]=m2;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return func(arr,k,dp,0);
    }
};