class Solution {
public:
    int func(int i,string s,vector<int> &dp){
        if(i>=s.size()) return 1;
        if(s[i]=='0') return 0;
        if(i==s.size()-1) return 1;
        if(dp[i]!=-1) return dp[i];
        int a=func(i+1,s,dp);
        int b=0;
        if(s[i]=='1'){
            b=func(i+2,s,dp);
        }
        else if(s[i]=='2'){
            if(i+1<=s.size()-1){
                if(s[i+1]=='0'||s[i+1]=='1'||s[i+1]=='2'||s[i+1]=='3'||s[i+1]=='4'||s[i+1]=='5'||s[i+1]=='6'){
                    b=func(i+2,s,dp);
                }
            }
        }
        return dp[i]=a+b;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return func(0,s,dp);
    }
};