class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long res=1000000;
        int ind=0;
        long long sum1=0;
        for(int i=0;i<nums.size();++i)
            sum1+=nums[i];
        long long temp=0;
        for(int i=0;i<nums.size();++i){
            sum1-=nums[i];
            temp+=nums[i];
            long long t=0;
            t+=temp/(i+1);
            if((nums.size()-i-1)!=0){
                t=t-sum1/(nums.size()-i-1);
            }
            else{
                t=t-sum1;
            }
            // t=temp/(i+1)-sum1/(nums.size()-i-1);
            t<0?t=-t:t=t;
            // res=min(t,res);
            // cout<<t<<endl;
            if(res>t){
                cout<<t<<" "<<i<<endl;
                res=t;
                ind=i;
            }
        }
        return ind;
    }
};