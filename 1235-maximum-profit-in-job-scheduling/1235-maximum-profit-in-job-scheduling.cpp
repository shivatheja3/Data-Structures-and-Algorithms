class Solution {
public:
    int bSearch(vector<int>& st,vector<int>& en,int ind){
        int x=en[ind];
        int s=ind+1;
        int e=st.size()-1;
        while(s<=e){
            int m=(s+e)/2;
            if(st[m]<x)
                s=m+1;
            else
                e=m-1;
        }
        return s;
    }
    int func(int s,int e,vector<int>& st, vector<int>& en, vector<int>& pr,int i,vector<int> &dp){
        if(i==st.size())
            return 0;
        if(st[i]<e)
            return func(s,e,st,en,pr,i+1,dp);
        if(dp[i]!=-1) return dp[i];
        int b=func(s,e,st,en,pr,i+1,dp);
        int a=0;
        // here binary search is used to find the index in the array with greater than current startTime
        int nextIndex=bSearch(st,en,i);
        // after pr, i+1 is replaced by nextIndex
        a=pr[i]+func(min(s,st[i]),max(e,en[i]),st,en,pr,nextIndex,dp);
        return dp[i]=max(a,b);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        for(int i=0;i<startTime.size();++i)
            v.push_back({startTime[i],endTime[i],profit[i]});
        sort(v.begin(),v.end());
        for(int j=0;j<startTime.size();++j){
            startTime[j]=v[j][0];
            endTime[j]=v[j][1];
            profit[j]=v[j][2];
        }
        vector<int> dp(startTime.size(),-1);
        return func(-1,-1,startTime,endTime,profit,0,dp);
    }
};