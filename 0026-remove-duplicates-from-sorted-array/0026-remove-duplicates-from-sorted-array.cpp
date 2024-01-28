class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int l1=0;
        int l2=1;
        while(l2<nums.size()){
            if(nums[l2]==nums[l1]){
                ++l2;
            }
            else{
                // cout<<l1<<" "<<l2<<endl;
                ++l1;
                ++l2;
                nums[l1]=nums[l2-1];
            }
        }
        // if(nums[l1])
        nums[l1]=nums[nums.size()-1];
        return l1+1;
    }
};