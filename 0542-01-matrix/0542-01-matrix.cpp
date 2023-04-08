class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int rows=mat.size();
        int cols=mat[0].size();
        vector<vector<int>> dp(rows,vector<int> (cols,1000000));
        for(int i=0;i<mat.size();++i){
            for(int j=0;j<mat[i].size();++j){
                if(mat[i][j]==0){
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        
        int d[4][2]={{ -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }};
        while(q.size()!=0){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                if((a+d[i][0])>=0&&(a+d[i][0])<rows&&(b+d[i][1])>=0&&(b+d[i][1])<cols){
                    if(dp[a+d[i][0]][b+d[i][1]]>(dp[a][b]+1)){
                        dp[a+d[i][0]][b+d[i][1]]=dp[a][b]+1;
                        q.push({a+d[i][0],b+d[i][1]});
                    }
                }
            }
        }
        return dp;
    }
};