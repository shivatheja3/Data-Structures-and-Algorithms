class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int ans=0,p1=0,p2=p.size()-1;
        sort(p.begin(),p.end());
        // int c=limit;
        while(p1<=p2){
            if((p[p1]+p[p2])<=limit){
                // c-=p[p1]+p[p2];
                ++p1;
                --p2;
            }
            else if(p[p2]<=limit){
                // c-=p[p2];
                --p2;
            }
             // else{
                // c=limit;
                ++ans;
            // }
        }
        return ans;
    }
};