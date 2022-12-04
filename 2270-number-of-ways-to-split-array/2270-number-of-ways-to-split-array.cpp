class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum1=0;
        int res=0;
        for(int i=0;i<nums.size();++i)
            sum1+=nums[i];
        long long t=0;
        for(int i=0;i<(nums.size()-1);++i){
            t+=nums[i];
            sum1-=nums[i];
            if(t>=sum1){
                ++res;
            }
        }
        return res;
    }
};