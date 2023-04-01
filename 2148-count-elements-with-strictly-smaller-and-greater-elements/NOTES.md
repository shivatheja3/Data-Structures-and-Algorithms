class Solution {
public:
int countElements(vector<int>& nums) {
int ans=0;
sort(nums.begin(),nums.end());
for(int i=1;i<(nums.size()-1);++i){
int f=-100001,c=-100001;
int l=0;
int r=nums.size()-1;
int m=(l+r)/2;
int target(nums[i]-1);
while(l<=r){
m=(l+r)/2;
if(nums[m]<=target){
f=nums[m];
l=m+1;
}
else{
r=m-1;
}
}
l=0;
r=nums.size()-1;
m=(l+r)/2;
target=nums[i]+1;
while(l<=r){
m=(l+r)/2;
if(nums[m]>=target){
c=nums[m];
r=m-1;
}
else{
l=m+1;
}
}
cout<<c<<" "<<f<<endl;
if(c!=-100001&&f!=-100001){
++ans;
}
}
return ans;
}
};