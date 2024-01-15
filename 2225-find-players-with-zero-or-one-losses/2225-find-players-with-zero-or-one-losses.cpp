class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> winners,loosers;
        for(int i=0;i<matches.size();++i){
            winners[matches[i][0]]++;
            loosers[matches[i][1]]++;
        }
        vector<vector<int>> ans;
        vector<int> a1,a2;
        for(auto i:winners){
            if(loosers[i.first]==0){
                a1.push_back(i.first);
            }
        }
        for(auto i:loosers){
            if(i.second==1){
                a2.push_back(i.first);
            }
        }
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        ans.push_back(a1);
        ans.push_back(a2);
        return ans;
    }
};