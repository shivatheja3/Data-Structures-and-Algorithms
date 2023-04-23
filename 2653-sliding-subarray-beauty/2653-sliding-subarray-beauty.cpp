class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> res;
        int n=nums.size();
        map<int,int> h1;
        for(int i=0;i<k;++i){
            if(nums[i]<0)
                h1[nums[i]]++;
        }
        int ch=0;
        int c=0;
        for(auto j:h1){
            // for(int k=1;k<=j.second;++k){
                c+=j.second;
                if(c>=x){
                    ch=1;
                    res.push_back(j.first);
                    break;
                }
            // }
        }
        if(ch==0)
            res.push_back(0);
        for(int i=k;i<n;++i){
            if(h1[nums[i-k]]>0)
                h1[nums[i-k]]--;
            if(h1[nums[i-k]]==0)
                h1.erase(nums[i-k]);
            if(nums[i]<0)
                h1[nums[i]]++;
            ch=0;
            c=0;
            for(auto j:h1){
                // for(int k=1;k<=j.second;++k){
                    c+=j.second;
                    if(c>=x){
                        ch=1;
                        res.push_back(j.first);
                        break;
                    }
                // }
            }
            if(ch==0)
                res.push_back(0);
        }
        return res;
    }
};