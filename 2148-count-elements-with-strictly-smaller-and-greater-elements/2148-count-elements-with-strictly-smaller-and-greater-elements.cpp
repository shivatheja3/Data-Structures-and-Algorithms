class Solution {
public:
    int countElements(vector<int>& nums) {
        // cout<<count(*max_element(nums.begin(),nums.end()))<<endl;
        int m1=*max_element(nums.begin(),nums.end());
        int m2=*min_element(nums.begin(),nums.end());
        if(m1==m2)
            return 0;
        int c1=0,c2=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==m1)
                ++c1;
            if(nums[i]==m2)
                ++c2;
        }
        return nums.size()-c1-c2;
    }
};