class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0;
        for(i=0;i<word.size();++i){
            if(word[i]==ch){
                break;
            }
        }
        if(i<word.size()){
            for(int j=0;j<=(i/2);++j){
            char temp=word[j];
            word[j]=word[i-j];
            word[i-j]=temp;
        }
        }
        
        return word;
    }
};