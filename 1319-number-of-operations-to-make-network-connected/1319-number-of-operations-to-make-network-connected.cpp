class Solution {
public:
    void bfs(vector<vector<int>> &mat,int n,int m,int s,vector<int> &vis){
        queue<int> q;
        vis[s]=1;
        q.push(s);
        while(q.size()!=0){
            int x=q.front();
            q.pop();
            vis[x]=1;
            for(int i=0;i<mat[x].size();++i){
                if(vis[mat[x][i]]==0){
                    if(x!=mat[x][i]){
                    q.push(mat[x][i]);
                    vis[mat[x][i]]=1;
                        }
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<(n-1)){
            return -1;
        }
        vector<vector<int>> mat;
        for(int i=1;i<=n;++i){
            mat.push_back({});
        }
        int m=connections.size();
        for(int i=0;i<m;++i){
            mat[connections[i][0]].push_back(connections[i][1]);
            mat[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> vis(n,0);
        int c=0;
        for(int i=0;i<n;++i){
            if(mat[i].size()==0){
                ++c;
                vis[i]=1;
            }
            else if(vis[i]==0){
                ++c;
                bfs(mat,n,m,i,vis);
            }
        }
        return c-1;
    }
};