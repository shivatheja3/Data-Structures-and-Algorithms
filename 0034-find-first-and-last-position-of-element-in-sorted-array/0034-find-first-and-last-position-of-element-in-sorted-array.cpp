class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> a;
        a.push_back(-1);
        a.push_back(-1);
        if(nums.size()==0){
            return a;
        }
        int l=0;
        int r=nums.size()-1;
        int m=(l+r)/2;
        int s=-1;
        while(l<=r){
            m=(l+r)/2;
            if(nums[m]==target){
                s=m;
                r=m-1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        int e=-1;
        if(s==-1){
            return a;
        }
        l=0;
        r=nums.size()-1;
        m=(l+r)/2;
        while(l<=r){
            m=(l+r)/2;
            if(nums[m]==target){
                e=m;
                l=m+1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        a[0]=s;
        a[1]=e;
        return a;
    }
};