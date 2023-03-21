class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<
            vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
            > pq;
        int c1=0;
        for(int i=0;i<matrix.size();++i){
            pq.push({matrix[i][0],i,0});
        }
        int m=matrix[0].size();
        int ans=0;
        while(!pq.empty()){
            ++c1;
            // cout<<c1<<endl;
            if(c1==k){
                ans=pq.top()[0];
                break;
            }
            // cout<<pq.size()<<endl;
            
            int ind1=pq.top()[1];
            int ind2=pq.top()[2];
            // cout<<ind1<<" "<<ind2<<endl;
            pq.pop();
            if((ind2+1)<m){
                pq.push({matrix[ind1][ind2+1],ind1,ind2+1});
            }
        }
        return ans;
    }
};