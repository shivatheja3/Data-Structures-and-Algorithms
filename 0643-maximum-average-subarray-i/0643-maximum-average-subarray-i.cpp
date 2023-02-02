class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res=-100000;
        for(int i=1;i<nums.size();++i){
            nums[i]+=nums[i-1];
        }
        int x=0;
        for(int i=(k-1);i<nums.size();++i){
            if(double((nums[i]-x))/k>res){
                cout<<i<<" "<<(nums[i]-x)<<endl;
                res=double(nums[i]-x)/k;
            }
            x=nums[i-(k-1)];
        }
        return res;
    }
};