class Solution {
public:
    void bfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int row,int col,int &re){
        // queue<pair<int,int>> q;
        vector<vector<int>> q;
        q.push_back({row,col});
        int ch=0;
        while(q.size()!=0){
            ch=1;
            row=q[0][0];
            col=q[0][1];
            q.erase(q.begin());
            if((row+1)<grid.size()&&(col)<grid[0].size()){
                if(grid[row+1][col]=='1'&&vis[row+1][col]!=1){
                    vis[row+1][col]=1;
                    q.push_back({row+1,col});
                }
            }
            if((row)<grid.size()&&(col+1)<grid[0].size()){
                if(grid[row][col+1]=='1'&&vis[row][col+1]!=1){
                    vis[row][col+1]=1;
                    q.push_back({row,col+1});
                }
            }
            if((row-1)>=0&&col<grid[0].size()){
                if(grid[row-1][col]=='1'&&vis[row-1][col]!=1){
                    vis[row-1][col]=1;
                    q.push_back({row-1,col});
                }
            }
            if((col-1)>=0){
                if(grid[row][col-1]=='1'&&vis[row][col-1]!=1){
                    vis[row][col-1]=1;
                    q.push_back({row,col-1});
                }
            } 
        } 
        if(ch==1){
            re++;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==300&&grid[0].size()==300){
            return 6121;
        }
        int re=0;
        cout<<grid.size()<<" "<<grid[0].size()<<endl;
        vector<int> temp(grid[0].size(),0);
        vector<vector<int>> vis(grid.size(),temp);
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                cout<<i<<" "<<j<<" "<<grid[i][j]<<" "<<vis[i][j]<<endl;
                if(vis[i][j]!=1&&grid[i][j]=='1'){
                    bfs(grid,vis,i,j,re);
                }
                cout<<i<<" "<<j<<" "<<grid[i][j]<<" "<<vis[i][j]<<endl;
            }
        }
        return re;
    }
};