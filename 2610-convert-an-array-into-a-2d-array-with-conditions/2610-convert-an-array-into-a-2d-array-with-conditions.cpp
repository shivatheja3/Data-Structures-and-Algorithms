#include <algorithm> 
#include <functional> 
#include <iostream> 
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
         unordered_map<int,int> h1;
        for(int i=0;i<nums.size();++i)
            h1[nums[i]]++;
        vector<vector<int>> temp;
        for(auto i:h1)
            temp.push_back({i.second,i.first});
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        vector<vector<int>> ans(temp[0][0],{temp[0][1]});
        for(int i=1;i<temp.size();++i){
            int c=0;
            while(temp[i][0]!=0){
                ans[c++].push_back(temp[i][1]);
                temp[i][0]--;
            }
        }
        return ans;
    }
};