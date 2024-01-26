class Solution {
public:
    int M = 1000000007;
    int func(int m, int n, int ma, int x, int y,vector<vector<vector<int>>> &dp){
        if(x<0||x>=m||y<0||y>=n){
            return 1;
        }
        if(ma==0){
            return 0;
        }
        if(dp[x][y][ma]>=0) return dp[x][y][ma];
        int a=func(m,n,ma-1,x+1,y,dp);
        int b=func(m,n,ma-1,x,y-1,dp);
        int c=func(m,n,ma-1,x-1,y,dp);
        int d=func(m,n,ma-1,x,y+1,dp);
        return dp[x][y][ma]=((a+b)%M+(c+d)%M)%M;
    }
    int findPaths(int m, int n, int ma, int x, int y) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(ma+1,-1)));
        return func(m,n,ma,x,y,dp);
    }
};
// class Solution {
// public:
//     int findPaths(int m, int n, int ma, int x, int y) {
//         int ans=0;
//         queue<vector<int>> q;
//         q.push({x,y,ma});
//         vector<int> dx{1,0,-1,0};
//         vector<int> dy{0,-1,0,1};
//         // brute force n--> 4 traversal by taking all possiblites
//         // this approach leads to tle.
//         // this is iterative using queue
//         while(q.size()!=0){
//             vector<int> temp=q.front();
//             q.pop();
//             if(temp[2]==0){
//                 if(temp[0]<0||temp[0]>=m||temp[1]<0||temp[1]>=n){
//                     ++ans;
//                 }
//                 continue;
//             }
//             if(temp[0]<0||temp[0]>=m||temp[1]<0||temp[1]>=n){
//                 ++ans;
//                 continue;
//             }
//             int a=temp[0];
//             int b=temp[1];
//             for(int i=0;i<=3;++i){
//                 q.push({a+dx[i],b+dy[i],temp[2]-1});
//             }
//         }
//         return ans;
//     }
// };