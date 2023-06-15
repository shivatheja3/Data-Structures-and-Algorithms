class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // intution is any way we have to use stack which takes O(n) space
        // so use one more vector<char> to split every character in s
        vector<char> exp;
        vector<pair<char,int>> v;
        pair<char,int> p;
        char x='-';
        for(int i=0;i<s.size();++i){
            if(s[i]!='('&&s[i]!=')'){
                exp.push_back(s[i]);
            }
            else{
                exp.push_back(x);
                p.first=s[i];
                p.second=i;
                v.push_back(p);
            }
        }
        string res="";
        stack<pair<char,int>> st;
        vector<pair<char,int>> r;
        for(int i=0;i<v.size();++i){
            if(v[i].first=='('){
                st.push(v[i]);
            }
            else{
                if(st.size()>0){
                    if(st.top().first=='('){
                        p=st.top();
                        st.pop();
                        r.push_back(p);
                        r.push_back(v[i]);
                    }
                    else{
                        v[i].first=x;
                        r.push_back(v[i]);
                    }
                }
            }
        }
        for(int i=0;i<r.size();++i){
            exp[r[i].second]=r[i].first;
        }
        for(int i=0;i<exp.size();++i){
            if(exp[i]!='-')
                res+=exp[i];
        }
        return res;
    }
};