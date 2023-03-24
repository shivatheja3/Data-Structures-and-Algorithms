class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<vector<int>> q;
        q.push({0});
        vector<vector<int>> res;
        int des=graph.size()-1;
        vector<int> vis(des+1,0);
        while(q.size()!=0){
            vector<int> temp=q.front();
            int x=temp[temp.size()-1];
            vis[x]=1;
            if(x==des){
                vis[x]=0;
            }
            q.pop();
            // cout<<x<<endl;
            for(int i=0;i<graph[x].size();++i){
                // if(vis[graph[x][i]]==0){
                    vector<int> t=temp;
                    t.push_back(graph[x][i]);
                    // cout<<graph[x][i]<<endl;
                    // for(int i=0;i<t.size();++i){
                    //     cout<<t[i]<<" ";
                    // }
                    // cout<<endl;
                    if(graph[x][i]==des){
                        res.push_back(t);
                    }
                    else{
                        q.push(t);
                    }
                // }
            }
        }
        return res;
    }
};