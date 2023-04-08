class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();++i){
            if(s[i]=='a'){
                st.push('a');
            }
            else if(s[i]=='b'){
                st.push('b');
            }
            else{
                if(st.size()>0){
                    if(st.top()=='b'){
                        if(st.size()>0){
                            st.pop();
                        }
                        else{
                            return false;
                        }
                        if(st.size()>0){
                            if(st.top()=='a'){
                                st.pop();
                            }
                            else{
                                return false;
                            }
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return st.size()==0;
    }
};