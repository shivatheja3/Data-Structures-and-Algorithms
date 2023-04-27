class Solution {
public:
    int cnt(int a){
        int c=0;
        while(a){
            ++c;
            a>>=1;
        }
        return c;
    }
    int rangeBitwiseAnd(int left, int right) {
        if(left==0||right==0)
            return 0;
        if(left==right)
            return left;
        if(right%left==0)
            return 0;
        if(cnt(left)<cnt(right))
            return 0;
        long long int res=left;
        long long int i=left+1;
        for(i=left+1;i<=right;i++){
            //printf("%d %d\n",i,res);
            res&=i;
            if(res==0){
                return 0;
            }
        }
        return res;
    }
};