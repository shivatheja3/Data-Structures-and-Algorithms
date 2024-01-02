class Solution {
public:
    void func(int i,int n,int k,vector<int> &temp,vector<vector<int>> &ans){
        if(temp.size()<k&&i>n){
            return;
        }
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        temp.push_back(i);
        func(i+1,n,k,temp,ans);
        temp.pop_back();
        func(i+1,n,k,temp,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(1,n,k,temp,ans);
        return ans;
    }
};