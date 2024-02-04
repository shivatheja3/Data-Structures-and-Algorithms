class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m1=nums[0],i=0;
        for(i=0;i<nums.size();++i){
            if(m1>=nums.size()-1) return 1;
            if((nums[i]+m1)==i) return 0;
            m1=max(m1,nums[i]+i);
        }
        return i>=(nums.size()-1);
    }
};
// [2,3,0,3,1,0,1]