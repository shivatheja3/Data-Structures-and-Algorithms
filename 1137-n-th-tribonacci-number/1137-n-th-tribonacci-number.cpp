class Solution {
public:
    int tribonacci(int n) {
        int t0=0;
        if(n==0)
            return t0;
        int t1=1;
        if(n==1)
            return t1;
        int t2=1;
        if(n==2)
            return t2;
        int res=0;
        for(int i=3;i<=n;++i){
            res=t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=res;
        }
        return res;
            
    }
};