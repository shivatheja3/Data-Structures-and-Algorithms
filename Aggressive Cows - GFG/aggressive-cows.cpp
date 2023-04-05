//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
bool func(vector<int> &arr,int n,int c,int val){
    int s=0;
    int t=c-1;
    // cout<<t<<endl;
    for(int i=1;i<n&&t!=0;++i){
        if((arr[i]-arr[s])>=val){
            s=i;
            t--;
        }
    }
    // cout<<t<<" "<<val<<endl;
    if(t!=0){
        return false;
    }
    return true;
}

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int s=1;
        int e=stalls[n-1]-1;
        int c=k;
        int m=0;
        int mid=(s+e)/2;
        while(s<=e){
            mid=(s+e)/2;
            if(func(stalls,n,c,mid)){
                if(mid>m){
                    m=mid;
                }
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return m;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends