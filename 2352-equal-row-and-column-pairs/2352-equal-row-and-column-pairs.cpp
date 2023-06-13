class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<long,long> h1,h2;
        int v=pow(10,9)+7;
        int n=grid.size();
        for(int i=0;i<n;++i){
            long long x=0,y=0;
            for(int j=0;j<n;++j){
                x=((x*10)%v+grid[i][j])%v;
                y=((y*10)%v+grid[j][i])%v;
            }
            h1[x]++;
            h2[y]++;
        }
        int res=0;
        for(auto i:h1)
            res+=h2[i.first]*i.second;
        return res;
    }
};