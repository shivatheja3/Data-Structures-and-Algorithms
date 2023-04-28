class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0||c==1||c==2)
            return true;
        if(c==3)
            return false;
        int l=0,r=sqrt(c);
        while(l<=r){
            if((long long)((long long)l*l+(long long)r*r)==c)
                return true;
            else if((long long)((long long)l*l+(long long)r*r)>c){
                --r;
            }
            else{
                ++l;
            }
        }
        return false;
    }
};