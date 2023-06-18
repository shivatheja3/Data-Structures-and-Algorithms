//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	int min1=INT_MAX,max1=INT_MIN,i=0;
    	for(i=0;i<N&&(i+1)<N;i+=2){
    	    int minTemp,maxTemp;
    	    if(A[i]<A[i+1]){
    	        minTemp=A[i];
    	        maxTemp=A[i+1];
    	    }
    	    else{
    	        minTemp=A[i+1];
    	        maxTemp=A[i];
    	    }
    	    if(minTemp<min1){
    	        min1=minTemp;
    	    }
    	    if(maxTemp>max1){
    	        max1=maxTemp;
    	    }
    	   // cout<<minTemp<<" "<<maxTemp<<endl;
    	}
    	
    	if(i==(N-1)){
    	    if(A[i]<min1){
    	        min1=A[i];
    	    }
    	    if(A[i]>max1){
    	        max1=A[i];
    	    }
    	}
    // 	cout<<min1<<" "<<max1<<endl;
    	return max1+min1;
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends