#include<bits/stdc++.h>
class Solution {
public:
    string simplifyPath(string path) {
        string res="";
        stack <string> tokens;
        for(int i=0;i<path.size();++i){
            if(path[i]=='/')
                continue;
            string temp="";
            while(i<path.size()&&path[i]!='/')
                temp+=path[i++];
            if(temp==".")
                continue;
            else if(temp==".."){
                if(tokens.size()>0)
                    tokens.pop();
            }
            else{
                tokens.push(temp);
            }
        }
        while(tokens.size()!=0){
            res="/"+tokens.top()+res;
            tokens.pop();
        }
        if(res.size()==0)
            res+="/";
        return res;
    }
};