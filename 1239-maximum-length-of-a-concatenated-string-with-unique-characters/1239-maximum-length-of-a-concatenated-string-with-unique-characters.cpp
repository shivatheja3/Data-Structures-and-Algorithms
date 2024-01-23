class Solution {
public:
    int func(int ind,vector<string> &arr,string s,unordered_map<char,int> &h1){
        if(ind==arr.size()){
            bool ans=true;
            for(auto i:h1){
                if(i.second>1){
                    ans=false;
                    break;
                }
            }
            if(ans) return s.size();
            return 0;
        }
        string temp=s;
        for(int i=0;i<arr[ind].size();++i){
            s+=arr[ind][i];
            h1[arr[ind][i]]++;
        }
        int a=func(ind+1,arr,s,h1);
        for(int i=0;i<arr[ind].size();++i){
            h1[arr[ind][i]]--;
        }
        int b=func(ind+1,arr,temp,h1);
        return max(a,b);
    }
    int maxLength(vector<string>& arr) {
        unordered_map<char,int> h1;
        string s="";
        // vector<int> a;
        // a.push_back(0);
        return func(0,arr,s,h1);
        // return a[0];
    }
};