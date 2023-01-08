class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        vector<int> res(nums.size(),0);
        int c0=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                c0++;
            }
            else{
                prod*=nums[i];
            }
        }
        if(c0==0){
            for(int i=0;i<nums.size();++i){
                res[i]=prod/nums[i];
            }
        }
        else if(c0==1){
            for(int i=0;i<nums.size();++i){
                if(nums[i]==0){
                    res[i]=prod;
                }
                else{
                    res[i]=0;
                }
            }
        }
        return res;
    }
};