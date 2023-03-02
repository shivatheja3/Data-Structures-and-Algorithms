class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        // s+=chars[0];
        char prev=chars[0];
        int c=1;
        for(int i=1;i<chars.size();++i){
            if(chars[i]==prev){
                ++c;
            }
            else{
                s+=prev;
                if(c>1){
                    s+=to_string(c);
                }
                c=1;
                prev=chars[i];
            }
        }
        s+=prev;
        if(c>1){
            s+=to_string(c);
        }
        chars={};
        for(int i=0;i<s.size();++i){
            chars.push_back(s[i]);
        }
        return s.size();
//         for(int i=0;i<chars.size();++i){
            
//         }
    }
};