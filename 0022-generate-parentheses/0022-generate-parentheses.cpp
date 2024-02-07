class Solution {
public:
    void func(int n,int open,int close,vector<string> &res,string s){
        if(open==close&&n==open){
            res.push_back(s);
            return;
        }
        if(open<n)
            func(n,open+1,close,res,s+'(');
        if(close<open)
            func(n,open,close+1,res,s+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        func(n,0,0,res,s);
        return res;
    }
};