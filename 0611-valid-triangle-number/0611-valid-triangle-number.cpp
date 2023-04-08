class Solution {
public:
    int triangleNumber(vector<int>& t1) {
        int c=0;
        int n=t1.size();
        sort(t1.begin(),t1.end(),greater<int>());
        for(int i=0;i<(n-2);++i){
            int s=(i+1);
            int e=(n-1);
            while(s<e){
                if((t1[s]+t1[e])<=t1[i])
                    e--;
                else{
                    c+=(e-s);
                    s++;
                }
            }
        }
        return c;
    }
};