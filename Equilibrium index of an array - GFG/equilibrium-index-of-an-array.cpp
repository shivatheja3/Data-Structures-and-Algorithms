//{ Driver Code Starts
#include <iostream>
using namespace std;
#include <stdio.h>
 
int findEquilibrium(int [], int );
 
int main() {
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<findEquilibrium (a,n)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends


/* You are required to complete this method*/
int findEquilibrium(int A[], int n)
{
    if(n==1){
        return A[0];
    }
    int s1=A[0];
    int s2=0;
    for(int i=2;i<(n);++i){
        s2+=A[i];
    }
  for(int i=1;i<(n-1);++i){
      if(s1==s2){
          return i;
      }
      s1+=A[i];
      s2-=A[i+1];
  }
  return -1;
}