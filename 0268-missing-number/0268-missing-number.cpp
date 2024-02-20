class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=nums.size()*(nums.size()+1)/2;
        int res1=0;
        for(int i=0;i<nums.size();i++){
            res1+=nums[i];
        }
        return res-res1;
    }
};