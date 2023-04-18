class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<int> q;
        unordered_map<int,int> h1;
        for(int i=0;i<arr.size();++i){
            h1[arr[i]]++;
        }
        for(auto i:h1){
            q.push(i.second);
        }
        int n=arr.size();
        int x=n;
        int c=0;
        
        while(q.size()!=0){
            x-=q.top();
            ++c;
            if(x<=(n/2)){
                break;
            }
            q.pop();
        }
        return c;
    }
};