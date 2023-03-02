//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int bfs(vector<vector<int>> &a1,vector<vector<int>> &a,int d1,int d2,int n,int m){
        queue<vector<int>> q1,q2;
        int c=0;
        q1.push({0,0});
        int ch=2;
        a1[0][0]=1;
        vector<int> di{-1,0,0,1};
        vector<int> dj{0,-1,1,0};
        
        while(q1.size()!=0||q2.size()!=0){
            if(ch==1){
                int x1=q2.front()[0];
                int x2=q2.front()[1];
                q2.pop();
                a1[x1][x2]=1;
                for(int i=0;i<4;++i){
                    if(((x1+di[i])>=0&&(x1+di[i])<n)&&((x2+dj[i])>=0&&(x2+dj[i])<m)){
                        if(a1[x1+di[i]][x2+dj[i]]==0&&a[x1+di[i]][x2+dj[i]]==1){
                            if((x1+di[i])==d1&&(x2+dj[i])==d2){
                                return c+1;
                            }
                            q1.push({x1+di[i],x2+dj[i]});
                            a1[x1+di[i]][x2+dj[i]]=1;
                        }
                    }
                }
                if(q2.size()==0){
                    ch=2;
                    ++c;
                }
            }
            else{
                int x1=q1.front()[0];
                int x2=q1.front()[1];
                q1.pop();
                a1[x1][x2]=1;
                for(int i=0;i<4;++i){
                    if(((x1+di[i])>=0&&(x1+di[i])<n)&&((x2+dj[i])>=0&&(x2+dj[i])<m)){
                        if(a1[x1+di[i]][x2+dj[i]]==0&&a[x1+di[i]][x2+dj[i]]==1){
                            if((x1+di[i])==d1&&(x2+dj[i])==d2){
                                return c+1;
                            }
                            q2.push({x1+di[i],x2+dj[i]});
                            a1[x1+di[i]][x2+dj[i]]=1;
                        }
                    }
                }
                if(q1.size()==0){
                    ch=1;
                    ++c;
                }
            }
        }
        return -1;
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0){
            return -1;
        }
        int n=N;
        int m=M;
        int x=X;
        int y=Y;
        vector<vector<int>> a1;
        vector<int> t(m,0);
        for(int i=0;i<n;++i){
            a1.push_back(t);
        }
        // cout<<a1.size()<<" "<<a1[0].size()<<endl;
        // return 0;
        return bfs(a1,A,x,y,n,m);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends