}
vector<vector<int>> mat;
for(int i=0;i<n;++i){
mat.push_back({});
}
for(int i=0;i<e.size();++i){
mat[e[i][0]].push_back(e[i][1]);
mat[e[i][1]].push_back(e[i][0]);
}
vector<long long> a;
vector<int> vis(n,0);
for(int i=0;i<n;++i){
if(vis[i]==0){
bfs(mat,i,a,vis);
}
}
long long res=0;
long long sum1=0;
for(int i=1;i<a.size();++i){
sum1+=a[i];
}
for(int i=0;i<(a.size()-1);++i){
res+=a[i]*sum1;
sum1-=a[i+1];
}
return res;
}
};