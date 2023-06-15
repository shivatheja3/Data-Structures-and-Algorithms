//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string text1, string text2) 
	{ 
	    // Your code goes here
	    int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp;
        vector<int> t(text2.size()+1,0);
        for(int i=0;i<=text1.size();++i){
            dp.push_back(t);
        }
        for(int i=1;i<=text1.size();++i){
            for(int j=1;j<=text2.size();++j){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
            }
        }
        // int i=n;
        // int j=m;
        // string s="";
        // while(!(i<1||j<1)){
        //     if(text1[i-1]==text2[j-1]){
        //         s+=text1[i-1];
        //         i--;
        //         j--;
        //     }
        //     else{
        //         if(dp[i-1][j]>dp[i][j-1])
        //             --i;
        //         else
        //             --j;
        //     }
        // }
        // reverse(s.begin(),s.end());
        // cout<<s<<endl;
        return n+m-2*dp[text1.size()][text2.size()];
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends