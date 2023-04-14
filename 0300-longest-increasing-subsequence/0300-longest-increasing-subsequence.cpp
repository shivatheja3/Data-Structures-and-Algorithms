class Solution {
public:
    int ceil(int target,vector<int> &l){
        int res=-1;
        int s=0;
        int e=l.size()-1;
        int m=(s+e)/2;
        while(s<=e){
            m=(s+e)/2;
            if(l[m]>=target){
                res=m;
                e=m-1;
            }
            else
                s=m+1;
        }
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> l{nums[0]};
        for(int i=1;i<nums.size();++i){
            if(nums[i]>l[l.size()-1])
                l.push_back(nums[i]);
            else if(nums[i]<l[0])
                l[0]=nums[i];
            else
                l[ceil(nums[i],l)]=nums[i];
        }
        return l.size();
    }
};