#include <numeric>
#include<iostream>
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0)) return -1;
        if(gas.size()==1){
            if(gas[0]>=cost[0]) return 0;
            return -1;
        }
        // for(int i=0;i<gas.size();++i){
        //     int currGas=gas[i],startInd=i,res=1;
        //     for(int j=startInd+1;j<gas.size();++j){
        //         if(currGas>=cost[j-1])
        //             currGas+=(-cost[j-1]+gas[j]);
        //         else{
        //             res=0;
        //             break;
        //         }
        //     }
        //     if(!res) continue;
        //     for(int j=0;j<startInd;++j){
        //         if(j==0){
        //             if(currGas>=cost[cost.size()-1])
        //                 currGas+=(-cost[cost.size()-1]+gas[j]);
        //             else{
        //                 res=0;
        //                 break;
        //             }
        //         }
        //         else{
        //             if(currGas>=cost[j-1])
        //                 currGas+=(-cost[j-1]+gas[j]);
        //             else{
        //                 res=0;
        //                 break;
        //             }
        //         }
        //     }
        //     if(res==1){
        //         if(startInd==0)
        //             if(currGas>=cost[cost.size()-1]) return 0;
        //         if(currGas>=cost[startInd-1]) return startInd;
        //     }
        // }
        vector<int> diff(gas.size(),0);
        for(int i=0;i<gas.size();++i){
            diff[i]=gas[i]-cost[i];
        }
        int s1=0;
        int ans=diff.size();
        for(int i=0;i<diff.size();++i){
            s1+=diff[i];
            if(s1<0){
                s1=0;
                ans=diff.size();
            }
            else{
                // return i;
                ans=min(ans,i);
            }
        }
        return ans;
    }
};