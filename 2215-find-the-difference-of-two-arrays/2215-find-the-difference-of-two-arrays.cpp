class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> h1,h2;
        for(int i=0;i<nums1.size();++i)
            h1[nums1[i]]++;
        for(int i=0;i<nums2.size();++i)
            h2[nums2[i]]++;
        vector<vector<int>> ans;
        ans.push_back({});
        ans.push_back({});
        for(auto i:h1){
            if(h2[i.first]==0)
                ans[0].push_back(i.first);
        }
        for(auto i:h2){
            if(h1[i.first]==0)
                ans[1].push_back(i.first);
        }
        return ans;
    }
};