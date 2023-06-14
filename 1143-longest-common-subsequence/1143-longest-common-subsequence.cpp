class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // int x=test1.size();
        // int y=text2.size();
        vector<vector<int>> dp;
        vector<int> t(text2.size()+1,0);
        for(int i=0;i<=text1.size();++i){
            dp.push_back(t);
        }
        for(int i=1;i<=text1.size();++i){
            for(int j=1;j<=text2.size();++j){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};