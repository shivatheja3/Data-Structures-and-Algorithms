class Solution {
public:
    int minOperations(string s) {
        int r1=0,r2=0;
        for(int i=0;i<s.size();++i){
            if(i%2==0){
                if(s[i]=='0') ++r1;
            }
            else{
                if(s[i]=='1') ++r1;
            }
        }
        for(int i=0;i<s.size();++i){
            if(i%2==1){
                if(s[i]=='0') ++r2;
            }
            else{
                if(s[i]=='1') ++r2;
            }
        }
        return min(r1,r2);
    }
};