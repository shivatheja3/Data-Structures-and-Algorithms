/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int l=1;
        long long int r=n;
        long long int mid=(l+r)/2;
        while(l<=r){
            mid=(l+r)/2;
            cout<<mid<<endl;
            if(guess(mid)==0){
                return mid;
            }
            else if(guess(mid)==1){
                l=mid+1;
                
            }
            else{
                r=mid-1;
            }
        }
        return mid;
    }
};