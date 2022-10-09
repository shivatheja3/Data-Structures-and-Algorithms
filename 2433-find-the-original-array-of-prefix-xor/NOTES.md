class Solution {
public:
vector<int> bin(int t){
vector<int> r{0,32};
int c=r.size()-1;
while(t){
r[c--]=t%2;
t/=2;
}
return r;
}
vector<int> findArray(vector<int>& pref) {
vector<int> res{pref[0]};
// vector<int> res1;
int x=0;
for(int i=1;i<pref.size();++i){
x=x^res[res.size()-1];
int r=pref[i];
vector<int> l1,r1;
l1=bin(x);
r1=bin(r);
vector<int> num;
for(int j=31;j>=0;--j){
if(r1[j]==0){
num.push_back(l1[i]);
}
else{
num.push_back(~l1[i]);
}
}
int res1=0;
int c=0;
for(int j=0;j<num.size();++j){
res1+=num[i]*pow(2,c++);
}
res.push_back(res1);
}
return res;
}
};