//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int> r;
        unordered_map<int,int> h1;
        for(int i=0;i<n;++i){
            h1[arr[i]]++;
            if(h1[arr[i]]>1){
                r.push_back(arr[i]);
                h1[arr[i]]=-100001;
            }
        }
        if(r.size()==0){
            r.push_back(-1);
        }
        sort(r.begin(),r.end());
        return r;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends