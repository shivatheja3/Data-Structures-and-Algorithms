class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res=0;
        for(int i=0;i<(colors.size()-1);++i){
            int s=i,e=i;
            for(int j=(i+1);j<colors.size();++j){
                if(colors[j]==colors[i]){
                    e=j;
                    continue;
                }
                else{
                    break;
                }
            }
            if(e==s){
                continue;
            }
            else{
                int sum1=0;
                int max1=INT_MIN;
                for(int j=s;j<=e;++j){
                    sum1+=neededTime[j];
                    if(neededTime[j]>max1){
                        max1=neededTime[j];
                    }
                }
                res+=(sum1-max1);
                i=(e-1);
            }
        }
        return res;
    }
};