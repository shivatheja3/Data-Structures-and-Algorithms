class Solution {
public:
    void findPermutations(int ind,vector<int> nums,vector<vector<int>> &res,vector<int> &r,unordered_map<int,int> &h){
        if(ind==nums.size()){
            res.push_back(r);
            return;
        }
        int i=0;
        for(i=0;i<nums.size();i++){
            if(h[nums[i]]==0){
                r.push_back(nums[i]);
                h[nums[i]]=1;
                findPermutations(ind+1,nums,res,r,h);
                h[nums[i]]=0;
                r.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> r;
        unordered_map<int,int> h;
        findPermutations(0,nums,res,r,h);
        return res;
    }
};