class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res=0;
        int s=0;
        unordered_map<int,int> h;
        for(int i=0;i<nums.size();++i){
            s+=nums[i];
            if(s==goal){
                ++res;
            }
            if(h[s-goal]>0){
                res+=h[s-goal];
            }
            h[s]++;
        }
        return res;
    }
};