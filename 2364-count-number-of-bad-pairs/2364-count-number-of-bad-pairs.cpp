class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res=0;
        unordered_map<long long,long long> h1;
        for(int i=0;i<nums.size();++i)
            ++h1[nums[i]-i];
        // logic is very simple transform the given condition my few manipulations and think ny applying few example on paper
        // (j-nums[j])!=(i-nums[i])  is also true
        for(auto it:h1){
            if(it.second>1)
                res+=(it.second)*(it.second-1)/2;
        }
        return nums.size()*(nums.size()-1)/2-res;
    }
};