#include <bits/stdc++.h> 
class Solution {
    public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        for(auto& i: arr){
            um[i]++;
        }

        vector<pair<int, int>> vec(um.begin(), um.end());
        sort(vec.begin(), vec.end(), cmp);
        int ans = vec.size();
        for(auto& i: vec){
            if(k - i.second >=0){
                k -= i.second; 
                um.erase(i.first);
            }
        }
        return um.size() ;

    }
};