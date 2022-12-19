// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l=1,r=n;
        long long ans=1;
        while(l<=r){
            long long int m=(l+r)/2;
            cout<<m<<" "<<isBadVersion(m)<<endl;
            if(isBadVersion(m)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};