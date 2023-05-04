class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> h;
        vector<int> res;
        int i=0;
        for(i=0;i<nums.size();i++){
            if(h.find(target-nums[i])==h.end()){
                h[nums[i]]=i;
            }
            else{
                res.push_back(i);
                res.push_back(h[target-nums[i]]);
                break;
            }
        }
        return res;
    }
};