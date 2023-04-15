class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int min1=nums[0];
        int ans=0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]>min1)
                ans=max(ans,nums[i]-min1);
            else
                min1=nums[i];
        }
        return ans;
    }
    
};