# long long fact(int a){
#         int i=1;
#         long long int res1=1;
#         for(i=1;i<=a;++i){
#             res1*=i;
#         }
#         return res1;
#     }
#     long long nCr(int a){
#         return fact(2*a)/(fact(a)*fact(a));
#     }
#     int numTrees(int n) {
#         if(n==1){
#             return 1;
#         }
#         vector<int> l1;
#         int i=1;
#         for(i=1;i<=(n);++i){
#             l1.push_back(i);
#         }
#         for(i=0;i<l1.size();++i){
#             cout<<l1[i]<<" ";
#         }
#         int res=0;
#         for(i=1;i<(l1.size()-1);++i){
#             res+=(nCr(i)/(i+1))*nCr(n-1-i)/(n-i);
#             // cout<<res<<endl;
#         }
#         // return 0;
#         res+=2*fact(2*(n-1))/(fact(n-1)*fact(n-1))/n;
#         // cout<<res<<endl;
#         // res+=fact(2*(n-1)/(fact(n-1)*fact(n-1)))/n;
#         return res;
#     }
# import math  
class Solution(object):
    def fact(self,a):
        res1=1
        for i in range(1,a+1):
            res1*=i
        return res1
    # def comb(self,a,b):
    #     return fact(2*(n-1-i)//pow(fact(n-1-i),2)
    def numTrees(self, n):
        if n==1:
            return 1
        l1=[x for x in range(1,n+1)]
        print(l1)
        res=0
        for i in range(1,len(l1)-1):
            res+=(self.fact(2*i))//pow(self.fact(i),2)//(i+1)*(self.fact(2*(n-1-i))//pow(self.fact(n-1-i),2))//(n-i)
            print(res)
        res+=2*(self.fact(2*(n-1))//(self.fact(n-1)*self.fact(n-1))//n)
        return res
            
            
        