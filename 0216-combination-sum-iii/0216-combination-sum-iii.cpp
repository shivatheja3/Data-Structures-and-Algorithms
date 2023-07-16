class Solution {
public:
    void f(int target,vector<int> &temp,int ind,vector<vector<int>> &res,int k){
        if(target==0&&temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i=ind;i<=9;++i){
            // if(i>ind&&candidates[i]==candidates[i-1]) continue;
            if(i>target||temp.size()>k) break;
            temp.push_back(i);
            f(target-i,temp,i+1,res,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        f(n,temp,1,res,k);
        return res;
    }
};