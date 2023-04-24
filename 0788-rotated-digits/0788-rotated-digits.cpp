class Solution {
public:
    int rotatedDigits(int n) {
        int res=0;
        for(int i=1;i<=n;++i){
            int x=i;
            int c1=0;
            int c2=0;
            int c3=0;
            int c=0;
            int ch=1;
            while(x!=0){
                if(x%10==0||x%10==1||x%10==8){
                    ++c1;
                }
                else if(x%10==2||x%10==5||x%10==6||x%10==9){
                    ++c2;
                }
                else if(x%10==4||x%10==7||x%10==3){
                    ++c3;
                }
                ++c;
                x/=10;
            }
            if(c==c1||c3>=1){
                // ch=0;
                // break;
            }
            else{
                ++res;
            }
        }
        return res;
    }
};