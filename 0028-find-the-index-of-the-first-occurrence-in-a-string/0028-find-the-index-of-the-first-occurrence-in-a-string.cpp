class Solution {
public:
    int strStr(string ha, string ne) {
        if(ne.size()>ha.size()){
            return -1;
        }
        else if(ne.size()==ha.size()){
            if(ne!=ha){
                return -1;
            }
            return 0;
        }
        int res=-1;
        string temp="";
        for(int i=0;i<ne.size();++i){
            temp+=ha[i];
        }
        if(temp==ne){
            return 0;
        }
        int s=1;
        for(int i=ne.size();i<ha.size();++i){
            temp="";
            for(int j=s;j<=i;++j){
                temp+=ha[j];
            }
            // cout<<temp<<endl;
            if(temp==ne){
                return s;
            }
            ++s;
        }
        return -1;
    }
};