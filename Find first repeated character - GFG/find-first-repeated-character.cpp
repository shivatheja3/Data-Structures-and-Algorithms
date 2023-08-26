//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    unordered_map<char,int> h1;
    string res="-1";
    for(int i=0;i<s.size();++i){
        if(h1.find(s[i])!=h1.end()){
            res=s[i];
            return res;
        }
        else{
            h1[s[i]]=i;
        }
    }
    return res;
}