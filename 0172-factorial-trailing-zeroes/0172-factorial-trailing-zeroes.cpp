class Solution {
public:
    int trailingZeroes(int n) {
        int c=0;
        for(int i=1;i<=n;++i){
            // if(i%5==0){
            //     ++c;
            // }
            int x=i;
            int c1=0;
            while(x%5==0){
                ++c1;
                x/=5;
            }
            c+=c1;
        }
        return c;
    }
};