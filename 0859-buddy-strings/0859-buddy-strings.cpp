class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        if(s==goal){
            vector<int> t(26,0);
            for(int i=0;i<s.size();++i){
                t[s[i]-97]++;
                if(t[s[i]-97]==2)
                    return true;
            }
            return false;
        }
        int firstInd=-1,secondInd=-1;
        int c=0;
        for(int i=0;i<s.size();++i){
            if(s[i]!=goal[i]){
                ++c;
                if(c==1)
                    firstInd=i;
                else if(c==2)
                    secondInd=i;
                else
                    return false;
            }
        }
        // if(c==0) return false;
        if(secondInd==-1) return false;
        // if(c==2){
            if(s[firstInd]==goal[secondInd]&&s[secondInd]==goal[firstInd])
                return true;
        // }
        return false;
        // return c==2?true:false;
    }
};