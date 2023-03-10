class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()<=1){
            return true;
        }
        string s1="";
        for(int i=0;i<s.size();++i){
            if(s[i]>=97&&s[i]<=122){
                s1+=s[i]-32;
            }
            else if(s[i]>=65&&s[i]<=90){
                s1+=s[i];
            }
            else if(s[i]>=48&&s[i]<=57){
                s1+=s[i];
            }
        }
        if(s1.size()<=1){
            return true;
        }
        for(int i=0;i<s1.size()/2;++i){
            if(s1[i]!=s1[s1.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};