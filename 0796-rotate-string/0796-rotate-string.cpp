class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        queue<char> q1,q2;
        for(int i=0;i<s.size();++i){
            q1.push(s[i]);
            q2.push(goal[i]);
        }
        for(int i=0;i<s.size();++i){
            if(q1==q2)
                return true;
            char s=q1.front();
            q1.pop();
            q1.push(s);
        }
        return false;
    }
};