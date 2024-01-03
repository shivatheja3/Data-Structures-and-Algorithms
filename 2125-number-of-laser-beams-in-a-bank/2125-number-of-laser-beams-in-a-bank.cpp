class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0;
        int sum=0;
        for(int i=0;i<bank.size();++i){
            int cnt=0;
            for(int j=0;j<bank[i].size();++j){
                cnt+=(bank[i][j]=='1'?1:0);
            }
            sum+=prev*cnt;
            if(cnt!=0){
                prev=cnt;
            }
        }
        return sum;
    }
};