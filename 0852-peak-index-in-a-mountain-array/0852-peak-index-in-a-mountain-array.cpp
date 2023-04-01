class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr[0]>arr[1])
            return 0;
        else if(arr[arr.size()-1]>arr[arr.size()-2])
            return arr.size()-1;
        int s=1;
        int e=arr.size()-2;
        int m=(s+e)/2;
        while(s<=e){
            m=(s+e)/2;
            if(arr[m]>arr[m+1]&&arr[m]>arr[m-1])
                return m;
            else if(arr[m]<arr[m+1])
                s=m+1;
            else
                e=m-1;
        }
        return 0;
    }
};