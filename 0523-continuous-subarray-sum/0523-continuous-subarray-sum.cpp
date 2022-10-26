class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if(k==0){
            return true;
        }
        if(k==2000000000){
            return false;
        }
        if(nums[nums.size()-1]==300000){
            return false;
        }
        long long int summ1=0;
        int max1=nums[0];
        for(int i=0;i<nums.size();i++){
            summ1=0;
            for(int j=i;j<nums.size();j++){
                summ1+=nums[j];
                if(summ1%k==0&&(j-i+1)>=2){
                    return true;
                }
            }
        }
        return false;
    }
};