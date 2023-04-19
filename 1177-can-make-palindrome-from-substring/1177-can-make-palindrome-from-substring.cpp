class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<vector<int>> r;
        vector<int> x(26,0);
        for(int i=0;i<s.size();++i){
            x[s[i]-97]++;
            r.push_back(x);
        }
        for(int i=0;i<queries.size();++i){
            unordered_map<char,int> h1;
            vector<int> t;
            if(queries[i][0]==0){
                t=r[queries[i][1]];
            }
            else{
                vector<int> t1=r[queries[i][1]];
                t=r[queries[i][0]-1];
                for(int j=0;j<t1.size();++j){
                    t[j]=t1[j]-t[j];
                }
            }
            int x=0;
            for(int j=0;j<26;++j){
                x+=t[j]%2;
            }
            if((x/2)<=queries[i][2])
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};