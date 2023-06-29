class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod =(1e9 + 7);
        vector<pair<int,int>> mat[n];
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        for(int i=0;i<roads.size();++i){
            mat[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            mat[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<int> paths(n,0);
        paths[0]=1;
        vector<long long> dist(n,LONG_MAX);
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            long long a=pq.top().first;
            long long b=pq.top().second;
            pq.pop();
            for(int i=0;i<mat[b].size();++i){
                long long x=mat[b][i].first;
                long long y=mat[b][i].second;
                // cout<<(a+y)<<" "<<dist[x]<<endl;
                if((a+y)<dist[x]){
                    dist[x]=(a+y);
                    pq.push({a+y,x});
                    paths[x]=paths[b];
                }
                else if((a+y)==dist[x]){
                    paths[x]=(paths[x]+paths[b])%mod;
                }
            }
        }
        return paths[n-1]%mod;
    }
};