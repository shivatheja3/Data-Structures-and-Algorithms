class Solution {
public:
    int rotatedDigits(int n) {
        int res=0;
        vector<int> dp(n+1,0);
        for(int i=1;i<=n&&i<=9;++i){
            if(i%10==2||i%10==5||i%10==6||i%10==9){
                dp[i]=1;
                ++res;
            }
            else if(i%10==3||i%10==4||i%10==7){
                dp[i]=-100;
            }
        }
        for(int i=10;i<=n;++i){
            if(dp[i/10]<0){
                dp[i]=-100;
                continue;
            }
            if(i%10==2||i%10==5||i%10==6||i%10==9){
                dp[i]=1;
            }
            else if(i%10==3||i%10==7||i%10==4){
                // continue;
                dp[i]=-100;
            }
            dp[i]+=dp[i/10];
            if(dp[i]>0){
                ++res;
            }
        }
        return res;
    }
};