class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int l=0,h=arr.size()-1;
        int m=(l+h)/2;
        while(l<=h){
            m=(l+h)/2;
            if(k==arr[m]){
                return 1;
            }
            if(arr[m]==arr[l]&&arr[l]==arr[h]){
                l++;
                h--;
                continue;
            }
            if(arr[m]>=arr[l]){
                if(k>=arr[l]&&k<=arr[m]){
                    h=m;
                }
                else{
                    l=m+1;
                }
            }
            else{
                if(k>=arr[m]&&k<=arr[h]){
                    l=m;
                }
                else{
                    h=m-1;
                }
            }
        }
        return 0;
    }
};