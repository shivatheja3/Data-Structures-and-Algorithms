class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> h1;
        int sum1=0;
        int res=0;
        for(int i=0;i<nums.size();++i){
            sum1+=nums[i];
            if(sum1==k){
                ++res;
            }
            if(h1[sum1-k]>0){
                res+=h1[sum1-k];
            }
            h1[sum1]++;
        }
        return res;
    }
};