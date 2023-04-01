class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size()-1;
        stack<pair<int,int>> st;
        pair<int,int> p;
        vector<int> res(n+1,0);
        for(int i=(n);i>=0;--i){
            while(st.size()>0&&t[i]>=st.top().first)
                st.pop();
            res[i]=(st.size()==0)?0:(st.top().second-i);
            p.first=t[i];
            p.second=i;
            st.push(p);
        }
        return res;
    }
};