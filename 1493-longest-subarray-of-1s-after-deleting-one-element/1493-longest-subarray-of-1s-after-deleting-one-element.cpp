class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k=1;
        int p1=0,p2=0;
        int c=0;
        for(int i=0;i<nums.size();++i){
            c+=nums[i];
        }
        if(c==0){
            return 0;
        }
        int temp=k;
        int res=1;
        while(p2<nums.size()){
            if(nums[p2]==1){
                ++p2;
            }
            else if(temp>0&&nums[p2]==0){
                --temp;
                ++p2;
            }
            else{
                if(nums[p1]==0)
                    temp++;
                ++p1;
            }
            if(temp<=0){
                res=max(res,p2-p1);
            }else{
            res=max(res,p2-p1);
            }
        }
        return res-1;
    }
};