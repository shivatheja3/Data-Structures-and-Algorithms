class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==1&&matrix[0].size()==1){
            if(matrix[0][0]!=target){
                return false;
            }
            else{
                return true;
            }
        }
        int i=0;
        for(i=0;i<matrix.size();i++){
            if(matrix[i][0]<target){
                continue;
            }
            else if(matrix[i][0]==target){
                return true;
            }
            else{
                break;
            }
        }
        if(i>0){
            i-=1;
        }
        
        int l=0;
        int r=matrix[i].size()-1;
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(matrix[i][mid]==target){
                return true;
            }
            else if(matrix[i][mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return false;
    }
};