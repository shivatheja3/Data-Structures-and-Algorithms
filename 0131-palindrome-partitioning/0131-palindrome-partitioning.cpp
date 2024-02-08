#include <bits/stdc++.h>
class Solution {
public:
    void func(int ind,vector<vector<string>> &res,string s1,vector<string> &temp,string s){
        if(ind==s.size()){
            string s2="";
            for(int i=0;i<temp.size();++i){
                s2+=temp[i];
            }
            string s3=s2;
            if(s3.size()==s.size()){
                bool res1=1;
                for(int i=0;i<temp.size();++i){
                    string s4=temp[i];
                    reverse(s4.begin(),s4.end());
                    if(s4!=temp[i]){
                        res1=0;
                        break;
                    }
                }
                if(res1==1){
                    res.push_back(temp);
                }
            }
            return;
        }
        func(ind+1,res,s1+s[ind],temp,s);
        temp.push_back(s1+s[ind]);
        func(ind+1,res,"",temp,s);
        temp.pop_back();
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        string s1="";
        func(0,res,s1,temp,s);
        return res;
    }
};