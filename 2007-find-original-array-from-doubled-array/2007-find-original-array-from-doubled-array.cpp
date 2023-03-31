class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2==1){
            return {};
        }
        sort(changed.begin(),changed.end());
        unordered_map<int,int> h1;
        for(int i=0;i<changed.size();++i){
            h1[changed[i]]++;
        }
        vector<int> res;
        for(int i=0;i<changed.size();++i){
            if(h1[changed[i]]>0){
                if(h1[changed[i]*2]==0)
                    return {};
                else if(changed[i]==0){
                    if(h1[0]>1){
                        h1[0]-=2;
                        res.push_back(0);
                    }
                    else{
                        return {};
                    }
                }
                else{
                    res.push_back(changed[i]);
                    h1[changed[i]]--;
                    h1[changed[i]*2]--;
                }
            }
        }
        return res;
    }
};