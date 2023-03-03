class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max1=*max_element(nums.begin(),nums.end());
        int sum1=0;
        for(int i=0;i<nums.size();++i){
            sum1+=nums[i];
            max1=max(max1,sum1);
            if(sum1<0){
                sum1=0;
            }
        }
        int sum2=0;
        int min1=*min_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            sum2+=nums[i];
            min1=min(sum2,min1);
            if(sum2>0){
                sum2=0;
            }
        }
        int sum3=0;
        for(int i=0;i<nums.size();++i){
            sum3+=nums[i];
        }
        int c=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<0){
                ++c;
            }
        }
        if(c==nums.size()){
            return *max_element(nums.begin(),nums.end());
        }
        return max({sum3-min1,max1,sum3});
    }
};