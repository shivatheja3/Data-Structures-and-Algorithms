#User function Template for python3

class Solution:
    def convertToWords(self, n):
        # code here
        h1={}
        h1[0]=""
        h1[1]="one"
        h1[2]="two"
        h1[3]="three"
        h1[4]="four"
        h1[5]="five"
        h1[6]="six"
        h1[7]="seven"
        h1[8]="eight"
        h1[9]="nine"
        h1[10]="ten"
        h1[11]="eleven"
        h1[12]="twelve"
        h1[13]="thirteen"
        h1[14]="fourteen"
        h1[15]="fifteen"
        h1[16]="sixteen"
        h1[17]="seventeen"
        h1[18]="eighteen"
        h1[19]="nineteen"
        h2={};
        h2[0]=""
        h2[2]="twenty"
        h2[3]="thirty"
        h2[4]="forty"
        h2[5]="fifty"
        h2[6]="sixty"
        h2[7]="seventy"
        h2[8]="eighty"
        h2[9]="ninety"
        r=[]
        x=n%1000
        n//=1000
        a=(x-x%100)
        b=((x-a)-(x-a)%10)//10
        b1 =(x-a)
        a//=100
        c=x%10
        s1=""
        if a>0:
            s1+=h1[a]+" hundred"
        if b>0 or c>0:
            if len(s1)>0 or n>0:
                s1+=" and "
            if b1 in h1:
                s1+=h1[b1]
            else:
                s1+=h2[b]
                s1+=" "
                s1+=h1[c]
        r.append(s1)
        # print(s1)
        l=[" thousand"," lakh"," crore"]
        cnt=0
        while n!=0:
            x=n%100
            s1=""
            a=(x-x%10)//10
            b=x%10
            if x in h1 and x>0:
                s1+=h1[x]+" "
            else:
                s1+=h2[a]
                if b>0:
                    s1+=" "+h1[b]
            # print(n,x,s1)
            if len(s1)>0:
                s1+=l[cnt]+" "
            cnt+=1
            r.append(s1)
            n//=100
        res=""
        r.reverse()
        for i in range(len(r)):
            s=r[i].strip()
            res+=s+" "
        res=res.strip()
        res=" ".join(res.split())
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        ob = Solution()
        ans = ob.convertToWords(n)
        print(ans)
        tc -= 1

# } Driver Code Ends