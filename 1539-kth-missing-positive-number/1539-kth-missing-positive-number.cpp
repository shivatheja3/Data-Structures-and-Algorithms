class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=n-1;
        int m=(l+r)/2;
        int res=-1;
        while(l<=r){
            m=(l+r)/2;
            if((nums[m]-(m+1))<k){
                l=m+1;
            }
            else{
                res=m;
                r=m-1;
            }
        }
        cout<<res<<endl;
        if(res==-1){
            // res=n+1;
            int c=nums[n-1]-n;
            for(int j=nums[n-1];;++j){
                if(c==k){
                    return j;
                }
                ++c;
            }
        }
        else if(res==0){
            int c=1;
            for(int j=1;j<=(nums[0]-1);++j){
                if(c==k)
                    return j;
                ++c;
            }
            
        }
        else if(res>0&&res<n){
            int k1=nums[res-1]-(res-1);
            int val1=nums[res-1]+1;
            int val2=nums[res]-1;
            for(int i=val1;i<=val2;++i){
                if(k1==k){
                    return i;
                }
                ++k1;
            }
        }
        return 0;
    }
};