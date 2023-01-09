class Solution {
public:
    int climbStairs(int n) {
        int a1=1,a2=1,a3=1;
        for(int i=2;i<=n;++i){
            a3=a1+a2;
            a1=a2;
            a2=a3;
        }
        return a3;
    }
};