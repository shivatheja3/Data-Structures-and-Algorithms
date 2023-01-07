class Solution {
public:
    string reverseWords(string s) {
        // Reversing the entire string
        int i,j;
        for(i=0;i<(s.size()/2);++i){
            char temp=s[i];
            s[i]=s[s.size()-1-i];
            s[s.size()-1-i]=temp;
        }
        // Reverse individual strings
        // return s;
        for(i=0;i<s.size();++i){
            if(s[i]!=' '){
                for(j=i;j<s.size();++j){
                    if(s[j]==' '){
                        break;
                    }
                }
                int l=i,r=j-1;
                i=r+1;
                while(l<r){
                    char temp=s[l];
                    s[l]=s[r];
                    s[r]=temp;
                    ++l;
                    --r;
                }
            }
        }
        // copy into result so that extra spaces can be trimmed
        string res="";
        int st=0,e=s.size()-1;
        for(i=0;i<s.size();++i){
            if(s[i]!=' '){
                st=i;
                break;
            }
        }
        for(i=(s.size()-1);i>=0;--i){
            if(s[i]!=' '){
                e=i;
                break;
            }
        }
        for(i=st;i<=e;++i){
            if(s[i]!=' '){
                res+=s[i];
            }
            else{
                if(res[res.size()-1]!=' '){
                    res+=' ';
                }
            }
        }
        return res;
    }
};