class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
        vector<int> res;
	    vector<int> indegree(V,0);
        vector<vector<int>> adj(V,res);
	    for(int i=0;i<pre.size();++i){
	        indegree[pre[i][0]]++;
            adj[pre[i][1]].push_back(pre[i][0]);
	    }
        
        // for(int i=0;i<pre.size();++)
	    queue<int> q;
	    for(int i=0;i<V;++i){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
        // for(int i=0;i<adj.size();++i){
        //     cout<<i<<" ";
        //     for(int j=0;j<adj[i].size();++j){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
	    while(q.size()!=0){
	        int x=q.front();
	        q.pop();
            // cout<<x<<endl;
	        res.push_back(x);
	        for(int i=0;i<adj[x].size();++i){
                // if(x==adj[x][i]) return {};
                // cout<<adj[x][i]<<endl;
	            indegree[adj[x][i]]--;
	            if(indegree[adj[x][i]]==0){
	                q.push(adj[x][i]);
	            }
	        }
	    }
        // cout<<res.size()<<endl;
        if(res.size()!=V) return {};
	    return res;
    }
};