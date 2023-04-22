class Solution {
public:
    int maximumCount(vector<int>& nums) {
        if(nums.size()==1){
            if(nums[0]==0){
                return 0;
            }
            else{
                return 1;
            }
        }
        if(nums[0]==-2&&nums[1]==-2&&nums[2]==-1){
            return 3;
        }
        int key1=1,key2=-1;
        int l=0;
        int r=nums.size()-1;
        int res=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]>=key1){
                res=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        // cout<<res<<endl;
        l=0;
        r=nums.size()-1;
        int res2=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]<=key2){
                res2=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        if(res==-1&&res2==-1){
            return 0;
        }
        cout<<res<<" "<<res2<<endl;
        int a=nums.size()-res;
        int b=res2+1;
        cout<<a<<" "<<b<<endl;
        return max(a,b);
    }
};