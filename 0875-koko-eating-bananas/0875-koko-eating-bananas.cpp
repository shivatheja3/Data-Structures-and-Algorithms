class Solution {
public:
    int minEatingSpeed(vector<int>& arr1, int h) {
        int x=*max_element(arr1.begin(),arr1.end());
        int l=1,r=x;
        long long h1=h;
        int res=0;
        while(l<=r){
            int m=(l+r)/2;
            long long c=0;
            vector<int> arr=arr1;
            for(int j=0;j<arr.size();++j){
                if(arr[j]%m==0){
                    c+=arr[j]/m;
                }
                else{
                    c+=arr[j]/m;
                    ++c;
                }
            }
            if(c<=h1){
                res=m;
                r=m-1;
            }
            else if(c>h1)
                l=m+1;
        }
        return res;
    }
};