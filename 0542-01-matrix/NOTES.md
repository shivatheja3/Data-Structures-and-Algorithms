if(mat[i][j]==0)
dp[i][j]=0;
else{
int a=i;
int b=j;
for(int i=0;i<4;++i){
if((a+di[i])>=0&&(a+di[i])<mat.size()&&(b+dj[i])>=0&&(b+dj[i])<mat[0].size()){
if(mat[a+di[i]][b+dj[i]]==0){
dp[i][j]=1;
break;
}
else if(mat[a+di[i]][b+dj[i]]!=0&&dp[a+di[i]][b+dj[i]]!=1000000){
// dp[i][j]=min(dp[i][j],dp)
dp[i][j]=min(dp[i][j],dp[a+di[i]][b+dj[i]]+1);
}
else{
bfs(dp,mat,i,j);
}
}
}
}
}
}
// bfs(mat,dp,8,0);
return dp;
}
};