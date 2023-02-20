//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    pair<int,int> res;
    sort(arr,arr+n);
    int r1=-1;
        int l=0,r=n-1;
        int m=(l+r)/2;
        while(l<=r){
            m=(l+r)/2;
            if(arr[m]<=x){
                r1=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        res.first=r1>=0?arr[r1]:-1;
        r1=-1;
    l=0;r=n-1;
    m=(l+r)/2;
    while(l<=r){
        m=(l+r)/2;
            if(arr[m]>=x){
                r1=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
    }
    res.second=r1>=0?arr[r1]:-1;
        
    return res;
}