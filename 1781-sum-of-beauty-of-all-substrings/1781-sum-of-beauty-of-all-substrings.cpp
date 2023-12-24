class Solution {
public:
    int beautySum(string s) {
        int res=0;
        for(int i=0;i<s.size();++i){
            unordered_map<int,int> h1;
            for(int j=i;j<s.size();++j){
                h1[s[j]-97]++;
                int m1=0;
                int m2=INT_MAX;
                for(auto iter:h1){
                    m1=max(m1,iter.second);
                    m2=min(m2,iter.second);
                }
                res+=(m1-m2);
            }
        }
        return res;
    }
};