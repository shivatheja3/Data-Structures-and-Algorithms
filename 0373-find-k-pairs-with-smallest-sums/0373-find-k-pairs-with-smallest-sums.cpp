class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<
            vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
            >
            pq;
        for(int i=0;i<nums1.size();++i){
            pq.push({nums1[i]+nums2[0],i,0});
        }
        int c1=0;
        vector<vector<int>> res;
        while(!pq.empty()){
            ++c1;
            if(c1==(k+1)){
                break;
            }
            res.push_back({nums1[pq.top()[1]],nums2[pq.top()[2]]});
            int ind1=pq.top()[1];
            int ind2=pq.top()[2];
            pq.pop();
            if((ind2+1)<nums2.size()){
                pq.push({nums1[ind1]+nums2[ind2+1],ind1,ind2+1});
            }
        }
        return res;
    }
};