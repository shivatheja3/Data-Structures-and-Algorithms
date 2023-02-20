class Solution {
public:
    int bSearchCeil(int s,int e,int key,vector<int> &nums){
        int l=s;
        int r=nums.size()-1;
        int m=(l+r)/2;
        int res=-1;
        while(l<=r){
            m=(l+r)/2;
            if(nums[m]>=key){
                res=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return res;
    }
    int bSearchFloor(int s,int e,int key,vector<int> &nums){
        int l=s;
        int r=nums.size()-1;
        int m=(l+r)/2;
        int res=-1;
        while(l<=r){
            m=(l+r)/2;
            if(nums[m]<=key){
                res=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return res;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long res=0;
        int n=nums.size();
        for(int i=0;i<(n-1);++i){
            int t1=lower-nums[i];
            int t2=upper-nums[i];
            
            int ind1=bSearchCeil(i+1,n,t1,nums);
            int ind2=0;
            // if(nums[i+1]>t2){
            //     ind2=ind1-1;
            // }
            // else{
            ind2=bSearchFloor(i+1,n,t2,nums);
            // }
            cout<<ind1<<" "<<ind2<<endl;
            if(ind2==-1||ind1==-1){
                
            }
            else{
            res+=(ind2-ind1+1);                
            }
        }
        return res;
    }
};