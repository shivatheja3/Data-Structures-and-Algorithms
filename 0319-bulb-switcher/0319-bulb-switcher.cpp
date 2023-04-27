class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0||n==1)
            return n;
        int res=0;
        for(int i=2;i<=n;i++){
            res++;
            if(i*i>n){
                break;
            }
        }
        return res;
    }
};