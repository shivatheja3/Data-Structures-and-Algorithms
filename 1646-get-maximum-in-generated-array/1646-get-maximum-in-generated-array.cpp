class Solution {
public:
    int getMaximumGenerated(int n) {
        int m=-1;
        vector<int> r(n+1,0);
        if(n>0)
            r[1]=1;
        for(int i=2;i<=n;++i){
            if(i%2==0)
                r[i]=r[i/2];
            else
                r[i]=r[i/2]+r[(i/2)+1];
        }
        return *max_element(r.begin(),r.end());
    }
};