class Solution(object):
    def largestNumber(self, n):
        if len(n)==2:
            if n[0]+n[1]==0:
                return "0"
        if sum(n)==0:
            return "0"
        for i in range(len(n)-1):
            for j in range(i+1,len(n)):
                # print(str(n[j])+str(n[i]),str(n[i])+str(n[j]))
                if int(str(n[j])+str(n[i]))>int(str(n[i])+str(n[j])):
                    temp=n[i]
                    n[i]=n[j]
                    n[j]=temp
                    # print(i,j)
        res=""
        print(n)
        for i in range(len(n)):
            res+=str(n[i])
        return res