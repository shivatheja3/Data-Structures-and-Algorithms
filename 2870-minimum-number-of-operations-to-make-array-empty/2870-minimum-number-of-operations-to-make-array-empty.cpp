class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0;
        unordered_map<int,int> h1;
        for(int i=0;i<nums.size();++i)
            h1[nums[i]]++;
        for(auto i:h1){
            int x=i.second;
            if(x==1)
                return -1;
            if(x%3==0)
                res+=x/3;
            else if(x%3==2)
                res+=(x/3)+1;
            else
                res+=((x-4)/3)+2;
        }
        return res;
    }
};