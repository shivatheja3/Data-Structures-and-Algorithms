class Solution {
public:
    int func(int i,int j,int m,int n,vector<vector<int>>& o,vector<vector<int>> &dp){
        if(i==m||j==n){
            return 201000;
        }
        if(i==m-1&&j==n-1){
            return o[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        // int a=dp[i+1][j];
        // int b=dp[i][j+1];
        // if(a==-1)
        int a=o[i][j]+func(i+1,j,m,n,o,dp);
        // if(b==-1)
        int b=o[i][j]+func(i,j+1,m,n,o,dp);
        dp[i][j]=min(a,b);
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // if(grid[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int a=func(0,0,m,n,grid,dp);
        for(int i=0;i<=m;++i){
            for(int j=0;j<=n;++j){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return a;
    }
};