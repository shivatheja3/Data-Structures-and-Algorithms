class Solution {
public:
    void findPermutations(int ind,vector<int> nums,vector<int> &r,unordered_map<int,int> &h,map<vector<int>,int> &h1){
        if(ind==nums.size()){
            h1[r]=1;
            return;
        }
        int i=0;
        for(i=0;i<nums.size();i++){
            if(h[i]==0){
                r.push_back(nums[i]);
                h[i]=1;
                findPermutations(ind+1,nums,r,h,h1);
                h[i]=0;
                r.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> r;
        unordered_map<int,int> h;
        map<vector<int>,int> h1;
        findPermutations(0,nums,r,h,h1);
        for(auto i:h1){
            res.push_back(i.first);
        }
        return res;
    }
};