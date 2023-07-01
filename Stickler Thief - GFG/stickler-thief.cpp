//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int func(int n,int i,int arr[],vector<int> &dp){
        if(i==(n-1)){
            return arr[i];
        }
        if(i==n) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int a=dp[i+1];
        int b=dp[i+2];
        // if(a==-1){
            a=arr[i]+func(n,i+2,arr,dp);
        // }
        // if(b==-1){
            b=func(n,i+1,arr,dp);
        // }
        dp[i]=max(a,b);
        return dp[i]==-1?0:dp[i];
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n,-1);
        return func(n,0,arr,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends