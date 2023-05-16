class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        int M=1e9+7;
        vector<long long>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        long long ans=0;
        for(int i=0;i<=n-3;i++){
            long long leftSum=pre[i];
            int l=i+1;
            int r=n-2;
            int p1=-1,p2=-1;
            //finding end point of range i.e. p2
            while(l<=r){
                int m=l+(r-l)/2;
                
                long long midSum=pre[m]-leftSum;
                long long rightSum=pre[n-1]-pre[m];
                if(midSum<=rightSum)
                    p2=m,l=m+1;
                else
                    r=m-1;
            }
            
            //finding start point of range i.e. p1
            l=i+1;
            r=p2;
            while(l<=r){
                int m=l+(r-l)/2;
                
                long long midSum=pre[m]-leftSum;
                if(leftSum<=midSum)
                    p1=m,r=m-1;
                else
                    l=m+1;
            }
            
            if(p1!=-1 && p2!=-1 && p1<=p2)
                ans+=(p2-p1+1);
            ans=ans%M;
        }
        return ans;
        
    }
};