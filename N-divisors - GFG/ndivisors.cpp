//{ Driver Code Starts

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
    int count(int A,int B,int N){ 
        int c=0;
        for(int i=A;i<=B;++i){
            int c1=0;
            int t=i;
            int j=1;
            for(j=1;j<sqrt(t);++j){
                if(t%j==0){
                    ++c1;
                }
            }
            // c+=(2)
            c1*=2;
            if(j*j==t){
                ++c1;
            }
            if(c1==N){
                ++c;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,N;
        cin>>A>>B>>N;
        Solution ob;
        cout << ob.count(A,B,N) << endl;
    }
    return 0; 
}
// } Driver Code Ends