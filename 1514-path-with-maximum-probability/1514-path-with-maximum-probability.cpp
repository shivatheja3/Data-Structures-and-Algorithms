class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> mat[n];
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<edges.size();++i){
            mat[edges[i][0]].push_back({edges[i][1],succProb[i]});
            mat[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        // double res=0;
        vector<double> dist(n,INT_MIN);
        dist[start]=1;
        pq.push({1,start});
        while(!pq.empty()){
            double a=pq.top().first;
            int b=pq.top().second;
            // cout<<a<<" "<<b<<endl;
            pq.pop();
            for(int i=0;i<mat[b].size();++i){
                int x=mat[b][i].first;
                double y=mat[b][i].second;
                if((a*y)>dist[x]){
                    dist[x]=a*y;
                    pq.push({dist[x],x});
                    // cout<<dist[x]<<endl;
                }
            }
        }
        return dist[end]==INT_MIN?0:dist[end];
    }
};