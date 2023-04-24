class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int i=0;i<stones.size();++i){
            q.push(stones[i]);
        }
        while(q.size()!=0){
            if(q.size()==1){
                return q.top();
            }
            int x=q.top();
            q.pop();
            int y=q.top();
            q.pop();
            if(x!=y){
                q.push(abs(x-y));
            }
        }
        return 0;
    }
};