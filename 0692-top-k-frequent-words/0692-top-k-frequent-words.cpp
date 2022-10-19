class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> h;
        vector<string> res;
        int i=0;
        for(i=0;i<words.size();i++){
            h[words[i]]++;
        }
        for(int j=1;j<=k;j++){
            int max1=-1;
            string a;
            for(auto i:h){
                // cout<<i.first<<" "<<i.second<<endl;
               if(max1<i.second){
                   // cout<<i.second<<endl;
                   max1=i.second;
                   a=i.first;
                }
                else if(max1==i.second){
                    if(a>i.first){
                        a=i.first;
                    }
                }
            }
            h[a]=0;
            // cout<<a<<endl;
            res.push_back(a);
        }
        return res;
    }
};