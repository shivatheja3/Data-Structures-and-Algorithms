class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> h1;
        // int max1=0,n1=0;
        for(int i=0;i<trust.size();++i){
            h1[trust[i][0]]=1;
        }
        // if(max1==(n-1)){
        //     return n1;
        // }
        for(int i=1;i<=n;++i){
            if(h1[i]==0){
                h1[i]=1;
            }
            else{
                h1[i]=0;
            }
        }
        
        for(auto i:h1){
            int c=0;
            if(i.second==1){
                for(int j=0;j<trust.size();++j){
                    if(trust[j][1]==i.first){
                        ++c;
                    }
                }
            }
            if(c==(n-1)){
                return i.first;
            }
        }
        return -1;
    }
};