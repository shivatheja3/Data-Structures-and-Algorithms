class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0){
            return true;
        }
        int i=0,j=0;
        while(i<t.size()){
            // cout<<i<<" "<<j<<endl;
            if(t[i]==s[j]){
                ++i;
                ++j;
                cout<<i<<" "<<j<<endl;
                if(j==s.size()){
                    return true;
                }
            }
            else{
                // j=0;
                ++i;
                // i=0;
            }
        }
        return false;
    }
};