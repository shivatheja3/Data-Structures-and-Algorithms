class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int ptr=0;
        for(int i=0;i<pushed.size();++i){
            st.push(pushed[i]);
            while(st.size()>0&&ptr<popped.size()&&popped[ptr]==st.top()){
                st.pop();
                ++ptr;
            }
        }
        for(int j=ptr;j<popped.size();++j){
            if(popped[j]!=st.top()){
                return false;
            }
            else{
                st.pop();
            }
        }
        return true;
    }
};