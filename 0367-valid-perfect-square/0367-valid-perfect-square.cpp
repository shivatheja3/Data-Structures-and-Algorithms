class Solution {
public:
    bool isPerfectSquare(int num) {
        long int i=1;
        for(i=1;;i++){
            if(i*i<num){
                continue;
            }
            else if(i*i==num){
                return true;
            }
            else{
                return false;
            }
        }
    }
};