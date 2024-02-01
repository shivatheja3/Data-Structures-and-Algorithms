class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<vector<int>> a;
        for(int i=0;i<nums.size();i+=3){
            if(!(nums[i+1]-nums[i]<=k&&nums[i+2]-nums[i]<=k)){
                return a;
            }
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return ans;
    }
};