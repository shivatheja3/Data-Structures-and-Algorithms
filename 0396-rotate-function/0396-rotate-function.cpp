class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int currSum=0,sum1=0;
        for(int i=0;i<nums.size();++i){
            sum1+=nums[i];
            currSum+=i*nums[i];
        }
        int max1=currSum;
        for(int i=(n-1);i>=0;--i){
            currSum+=(-nums[i]*(n-1))+sum1-nums[i];
            max1=max(max1,currSum);
        }
        return max1;
    }
};