class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a1(26,0);
        for(int i=0;i<s.size();++i){
            a1[s[i]-97]++;
            a1[t[i]-97]--;
        }
        int res=0;
        for(int i=0;i<26;++i){
            if(a1[i]>0){
                res+=a1[i];
            }
        }
        return res;
    }
};