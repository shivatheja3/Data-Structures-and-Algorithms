class Solution {
public:
    int minReorder(int n, vector<vector<int>>& con) {
        queue<int> q;
        q.push(0);
        int m=con.size();
        int ans=0;
        unordered_map<int,int> h1;
        vector<vector<int>> mat1,mat2;
        for(int i=0;i<n;++i){
            mat1.push_back({});
            mat2.push_back({});
        }
        for(int i=0;i<m;++i){
            mat1[con[i][0]].push_back(con[i][1]);
        }
        for(int i=0;i<m;++i){
            mat2[con[i][1]].push_back(con[i][0]);
        }
        while(q.size()!=0){
            int x=q.front();
            q.pop();
            h1[x]=1;
            // this below code m=takes much time we have to optimize by using more hash maps
            // for(int i=0;i<m;++i){
            //     if(con[i][0]==x&&h1[con[i][1]]==0){
            //         ++ans;
            //         int temp=con[i][0];
            //         con[i][0]=con[i][1];
            //         con[i][1]=temp;
            //         if(h1[con[i][0]]==0){
            //             q.push(con[i][0]);
            //         }
            //     }
            //     else if(con[i][1]==x&&h1[con[i][0]]==0){
            //         if(h1[con[i][0]]==0){
            //             q.push(con[i][0]);
            //         }
            //     }
            // }
            for(int i=0;i<mat1[x].size();++i){
                if(h1[mat1[x][i]]==0){
                    ++ans;
                    mat2[mat1[x][i]].push_back(x);
                    if(h1[mat1[x][i]]==0){
                        q.push(mat1[x][i]);
                    }
                }
            }
            for(int i=0;i<mat2[x].size();++i){
                if(h1[mat2[x][i]]==0){
                    q.push(mat2[x][i]);
                }
            }
            
        }
        return ans;
    }
};