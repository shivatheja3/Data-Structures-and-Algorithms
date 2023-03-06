for(i=0;i<n;++i){
if((nums[i]-(i+1))>=k){
break;
}
}
if(i==0){
int c=1;
for(int j=1;j<=(nums[0]-1);++j){
if(c==k){
return j;
}
++c;
}
}
else if(i==n){
int c=nums[n-1]-n;
for(int j=nums[n-1];;++j){
if(c==k){
return j;
}
++c;
}
}
else{
int val1=nums[i-1]+1;
int val2=nums[i]-1;
cout<<val1<<" "<<val2<<endl;
int k1=nums[i-1]-(i-1);
cout<<k1<<" "<<k<<endl;
for(int j=val1;j<=val2;++j){
if(k1==k){
return j;
}
++k1;
}
}
return 0;
}
};
​
Do the same iteration using binary search