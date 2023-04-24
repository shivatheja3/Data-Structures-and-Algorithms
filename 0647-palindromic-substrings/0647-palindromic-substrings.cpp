class Solution {
public:
    int countSubstrings(string s) {
        if(s.size()==1)
            return 1;
        if(s.size()==2){
            if(s[0]==s[1]){
                return 3;
            }
            return 2;
        }
        vector<int> t(s.size(),0);
        int res=0;
        vector<vector<int>> dp(s.size(),t);
        for(int i=0;i<s.size();++i){
            dp[i][i]=1;
            ++res;
        }
        for(int i=0;i<(s.size()-1);++i){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                ++res;
            }
        }
        int c=2;
        for(int i=0;i<s.size();++i){
            // cout<<i<<endl;
            for(int j=0;j<(s.size()-c);++j){
                // cout<<j<<" "<<(j+c)<<" ";
                dp[j][j+c]=(s[j]==s[j+c])&&(dp[j+1][j+c-1]==1);
                res+=dp[j][j+c];
            }
            // cout<<endl;
            ++c;
            if(c==(s.size()))
                break;
        }
        // for(int i=0;i<dp.size();++i){
        //     for(int j=0;j<dp[i].size();++j){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return res;
    }
};