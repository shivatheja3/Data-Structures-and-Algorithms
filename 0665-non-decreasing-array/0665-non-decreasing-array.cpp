class Solution {
public:
    bool check(vector<int> &nums){
        if(nums[0]>nums[nums.size()-1])
            return false;
        for(int i=0;i<(nums.size()-1);++i){
            if(nums[i]>nums[i+1])
                return false;
        }
        return true;
    }
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<=2)
            return true;
        for(int i=0;i<nums.size();++i){
            if(i==0){
                int x=-100001;
                x=nums[i];
                nums[i]=nums[i+1];
                if(check(nums))
                    return true;
                nums[i]=x;
            }
            else if(i>0&&i<(nums.size()-1)){
                int x=-100001;
                x=nums[i];
                nums[i]=nums[i-1];
                if(check(nums))
                    return true;
                nums[i]=x;
            }
            else{
                int x=-100001;
                if(nums[i]<nums[i-1]){
                    x=nums[i];
                    nums[i]=nums[i-1];
                }
                if(check(nums))
                    return true;
                if(x!=-100001)
                    nums[i]=x;
            }
        }
        return false;
    }
};