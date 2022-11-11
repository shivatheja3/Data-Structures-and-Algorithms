class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        else if(nums.size()==2){
            if(nums[0]==nums[1]){
                return 1;
            }
            else{
                return 2;
            }
        }
        int c=1;
        int x=nums[0];
        int i=1;
        for(i=1;i<nums.size();i++){
            if(nums[i]==x){
                continue;
            }
            else{
                x=nums[i];
                nums[c]=x;
                c++;
            }
        }
        return c;
    }
};