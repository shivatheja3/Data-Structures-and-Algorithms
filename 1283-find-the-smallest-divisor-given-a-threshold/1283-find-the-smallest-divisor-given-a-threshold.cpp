#include<cmath>
class Solution {
public:
    bool possible(int m,vector<int>& nums, int threshold){
        int ans=0;
        for(int i=0;i<nums.size();++i){
            ans+=ceil((double)nums[i]/(double)m);
        }
        return ans<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int m=(l+r)/2;
        int ans=0;
        while(l<=r){
            m=(l+r)/2;
            if(possible(m,nums,threshold)){
                ans=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};