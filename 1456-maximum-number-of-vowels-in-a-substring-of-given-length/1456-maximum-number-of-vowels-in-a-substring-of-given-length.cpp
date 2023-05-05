class Solution {
public:
    int maxVowels(string s, int k) {
        int val=0;
        int max1=0;
        for(int i=0;i<k;++i){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                ++val;
            max1=max(max1,val);
        }
        for(int i=k;i<s.size();++i){
            if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u')
                --val;
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                ++val;
            max1=max(max1,val);
        }
        return max1;
    }
};