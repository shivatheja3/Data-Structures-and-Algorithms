//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> res;
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;++i){
	        for(int j=0;j<adj[i].size();++j){
	            if(adj[i][j]==i) return 1;
	            indegree[adj[i][j]]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;++i){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(q.size()!=0){
	        int x=q.front();
	        q.pop();
	        res.push_back(x);
	        for(int i=0;i<adj[x].size();++i){
	            indegree[adj[x][i]]--;
	            if(indegree[adj[x][i]]==0){
	                q.push(adj[x][i]);
	            }
	        }
	    }
	    return !(res.size()==V);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends