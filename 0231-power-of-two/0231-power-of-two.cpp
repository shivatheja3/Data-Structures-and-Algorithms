class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }
        else if(n==1){
            return true;
        }
        else{
            int k=n;
            while(k){
                if(k==1){
                    return true;
                }
                if(k==0){
                    return false;
                }
                if(k%2==0){
                    k=k/2;
                }
                else{
                    break;
                }
            }
            printf("%d ",1%2);
            if(k==0){
                return true;
            }
            return false;
        }
    }
};