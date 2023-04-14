#include <bits/stdc++.h>
class Solution {
public:
    int mss(string &s,string &s1,int ind1,int ind2,vector<vector<int>> &dp){
        if(ind1==-1||ind2==-1)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(s[ind1]==s1[ind2])
            return 1+mss(s,s1,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]=max(mss(s,s1,ind1-1,ind2,dp),mss(s,s1,ind1,ind2-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp;
        vector<int> t(s.size(),-1);
        for(int i=0;i<s.size();++i){
            dp.push_back(t);
        }
        string s1=s;
        reverse(s1.begin(),s1.end());
        return mss(s,s1,s.size()-1,s.size()-1,dp);
    }
};