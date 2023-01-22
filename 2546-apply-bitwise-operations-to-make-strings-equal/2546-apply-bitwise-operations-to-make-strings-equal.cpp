class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if(s==target)
            return true;
        int c1s=0,c1t=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='1')
                ++c1s;
            if(target[i]=='1')
                ++c1t;
        }
        if(c1s>=1&&c1t>=1)
            return true;
        return false;
    }
};