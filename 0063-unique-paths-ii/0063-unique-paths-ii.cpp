class Solution {
public:
    int func(int i,int j,int m,int n,vector<vector<int>>& o,vector<vector<int>> &dp){
        if(i==m||j==n){
            return 0;
        }
        if(i==m-1&&j==n-1){
            return 1;
            // if(o[i][j])
        }
        if(o[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int a=dp[i+1][j];
        int b=dp[i][j+1];
        if(a==-1)
            a=func(i+1,j,m,n,o,dp);
        if(b==-1)
            b=func(i,j+1,m,n,o,dp);
        dp[i][j]=a+b;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return func(0,0,m,n,obstacleGrid,dp);
    }
};