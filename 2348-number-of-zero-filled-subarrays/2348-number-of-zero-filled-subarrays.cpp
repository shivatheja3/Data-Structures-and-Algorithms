class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // unordered_map<int,int> h1;
        long long res=0;
        long long c=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                ++c;
            }
            else{
                // h1[c]++;
                res+=c*(c+1)/2;
                c=0;
            }
        }
        if(c!=0){
            res+=c*(c+1)/2;
        }
        return res;
    }
};