class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // Brute force: for every node list all the reachable vertices 
        // then loop from 0 to n-1 and find for every node and find minimum vertices which can be reachable to all TC:O(n*(n+2)/2)
        // little optimized is perform bfs and find how many times the bfs is called and then remove the vertices which can be reachable from the other but this is complicated
        
        
        
        // now comes the optimzed
        
        // A node that does not have any incoming edge can only be reached by itself.
        //     Any other node with incoming edges can be reached from some other node.
        //    We only have to count the number of nodes with zero incoming edges. 
        unordered_map<int,int> h1;
        for(int i=0;i<edges.size();++i){
            h1[edges[i][1]]++;
        }
        vector<int> res;
        for(int i=0;i<n;++i){
            if(h1[i]==0)
                res.push_back(i);
        }
        return res;
    }
};