class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        vector<int> a1(26,0),a2(26,0);
        for(int i=0;i<word1.size();++i){
            a1[word1[i]-97]++;
            a2[word2[i]-97]++;
        }
        for(int i=0;i<26;++i){
            if((a1[i]==0&&a2[i]>0)||(a1[i]>0&&a2[i]==0)) return false;
        }
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        for(int i=0;i<26;++i){
            if(a1[i]!=a2[i]) return false;
        }
        return true;
    }
};