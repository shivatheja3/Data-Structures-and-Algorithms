class Solution {
public:
    // void findCombination(int ind,int t,vector<vector<int>> &res,vector<int> &r,vector<int> a){
    //     if(ind==a.size()){
    //         if(t==0){
    //             res.push_back(r);
    //         }
    //         return;
    //     }
    //     if(a[ind]<=t){
    //         r.push_back(a[ind]);
    //         // t-=a[ind];
    //         findCombination(ind,t-a[ind],res,r,a);
    //         r.pop_back();
    //         // t+=a[ind];
    //     }
    //     findCombination(ind+1,t,res,r,a);
    // }
    void findCombination(int ind,int target,vector<vector<int>> &res,vector<int> &r,vector<int> &a){
        if(target<0) return;
        if(target==0){
            res.push_back(r);
            return;
        }
        for(int i=ind;i<a.size();++i){
            if(a[i]>target) break;
            r.push_back(a[i]);
            findCombination(i,target-a[i],res,r,a);
            r.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> r;
        findCombination(0,target,res,r,candidates);
        return res;
    }
};