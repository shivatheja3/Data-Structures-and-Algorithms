class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        long long ans=0;
        int s=0,e=costs.size()-1;
        for(int i=0;i<k;++i){
            while(pq1.size()<candidates&&s<=e){
                pq1.push(costs[s++]);
            }
            while(pq2.size()<candidates&&e>=s){
                pq2.push(costs[e--]);
            }
            int a=INT_MAX;
            int b=INT_MAX;
            if(pq1.size()>0){
                a=pq1.top();
                // pq1.pop();
            }
            if(pq2.size()>0){
                b=pq2.top();
                // pq2.pop();
            }
            if(a<=b){
                pq1.pop();
                ans+=a;
            }
            else{
                pq2.pop();
                ans+=b;
            }
        }
        return ans;
    }
};