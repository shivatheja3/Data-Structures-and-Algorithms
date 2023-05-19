class Solution {
public:
    int bfs(int e,vector<int> &vis,vector<vector<int>> &mat){
        queue<int> q;
        q.push(e);
        int v=0,e1=0;
        while(q.size()!=0){
            vis[q.front()]++;
            int x=q.front();
            // cout<<x<<endl;
            ++v;
            for(int i=0;i<mat[x].size();++i){
                if(vis[mat[x][i]]==0){
                    // cout<<mat[x][i]<<" ";
                    vis[mat[x][i]]++;
                    q.push(mat[x][i]);
                }
                // cout<<endl;
            }
            e1+=mat[x].size();
            q.pop();
        }
        // cout<<v<<" "<<e1<<endl;
        if((v*(v-1))==e1)
            return 1;
        return 0;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> mat;
        vector<int> vis(n,0);
        // cout<<vis.size()<<endl;
        for(int i=0;i<n;++i){
            mat.push_back({});
        }
        for(int i=0;i<edges.size();++i){
            mat[edges[i][0]].push_back(edges[i][1]);
            mat[edges[i][1]].push_back(edges[i][0]);
        }
        int c=0;
        for(int i=0;i<n;++i){
            if(vis[i]==0)
                c+=bfs(i,vis,mat);
            // cout<<c<<endl;
        }
        return c;
    }
};