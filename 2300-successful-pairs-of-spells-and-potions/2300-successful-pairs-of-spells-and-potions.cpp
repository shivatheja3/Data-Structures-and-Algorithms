class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();++i){
            int s=0,e=potions.size()-1;
            int m=(s+e)/2;
            int ans=-1;
            long long a1,a2=0;
            while(s<=e){
                m=(s+e)/2;
                a1=potions[m];
                a2=spells[i];
                if(a1*a2>=success){
                    ans=m;
                    e=m-1;
                }
                else
                    s=m+1;
            }
            if(ans==-1)
                res.push_back(0);
            else
                res.push_back(potions.size()-ans);
        }
        return res;
    }
};