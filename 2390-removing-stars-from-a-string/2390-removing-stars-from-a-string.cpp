class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i=0;i<s.size();++i){
            if(s[i]!='*'){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        string res="";
        while(st.size()!=0){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};