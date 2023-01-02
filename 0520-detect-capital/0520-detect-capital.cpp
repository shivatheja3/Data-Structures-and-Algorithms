class Solution {
public:
    bool detectCapitalUse(string word) {
        int c1=0;
        int first=-1;
        for(int i=0;i<word.size();++i){
            if(word[i]>=65&&word[i]<=90){
                if(c1==0){
                    first=i;
                }
                ++c1;
            }
        }
        if(c1==0||c1==word.size()){
            return true;
        }
        else if(c1==1&&first==0){
            return true;
        }
        return false;
    }
};