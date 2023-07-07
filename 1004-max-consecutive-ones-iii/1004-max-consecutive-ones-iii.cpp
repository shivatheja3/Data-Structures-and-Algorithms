class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(k==0){
            int c=0;
            int res=0;
            for(int i=0;i<nums.size();++i){
                if(nums[i]==1){
                    ++c;
                    res=max(res,c);
                }
                else{
                    c=0;
                }
            }
            return res;
        }
        if(k>=nums.size()){
            return nums.size();
        }
        int p1=0,p2=0;
        int c=0;
        for(int i=0;i<nums.size();++i){
            c+=nums[i];
        }
        int res=0;
        if(c>=1){
            res=1;
        }
        if(c==0){
            return k;
        }
        int temp=k;
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
            res=max(res,p2-p1+1);
        }
        return res-1;
    }
};