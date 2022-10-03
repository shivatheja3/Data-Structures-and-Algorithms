class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int max1=INT_MIN;
        for(int i=0;i<(grid.size()-2);++i){
            for(int j=0;j<(grid[i].size()-2);++j){
                int s=grid[i][j+0]+grid[i][j+1]+grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j+0]+grid[i+2][j+1]+grid[i+2][j+2];
            cout<<s<<endl;
                if(max1<s){
                    max1=s;
                }
            }
        }
        return max1;
    }
};