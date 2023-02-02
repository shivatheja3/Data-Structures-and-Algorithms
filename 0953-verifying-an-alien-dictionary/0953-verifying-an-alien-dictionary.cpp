class Solution {
public:
    bool f(vector<string>& words, string order,unordered_map<char,int> &h1){
        if(words.size()==1)
            return true;
        int i=0,j=0;
        for(i=0;i<(words.size()-1);++i){
            int ch=0;
            for(j=0;j<words[i].size();++j){
                if(words[i][j]==words[i+1][j]){
                    continue;
                }
                else if(h1[words[i][j]]<h1[words[i+1][j]]){
                    ch=1;
                    break;
                }
                else{
                    return false;
                }
            }
            if(words[i].size()==words[i+1].size()||ch==1){
                continue;
            }
            else if(words[i].size()>words[i+1].size()){
                return false;
            }
            else{
                continue;
            }
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> h1;
        for(int i=0;i<order.size();++i)
            h1[order[i]]=(i+1);
        
        return f(words,order,h1);
    }
};