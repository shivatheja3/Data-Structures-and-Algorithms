class Solution {
public:
    int check(vector<int> h1,vector<int> h2){
        int i=0;
        for(i=0;i<h1.size();++i){
            if(h1[i]!=h2[i]){
                return 0;
            }
        }
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size()<p.size()){
            return res;
        }
        vector<int> h1,h2;
        int i=0;
        for(i=0;i<26;i++){
            h1.push_back(0);
            h2.push_back(0);
        }
        int n=p.size();
        for(i=0;i<n;++i){
            ++h1[p[i]-97];
            ++h2[s[i]-97];
        }
        if(check(h1,h2)==1){
            res.push_back(0);
        }
        --h2[s[0]-97];
        for(i=1;i<(s.size()-n+1);++i){
            ++h2[s[i+n-1]-97];
            if(check(h1,h2)==1){
                res.push_back(i);
            }
            --h2[s[i]-97];
        }
        return res;
    }
};