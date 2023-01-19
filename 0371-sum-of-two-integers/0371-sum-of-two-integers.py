class Solution(object):
    def getSum(self, a, b):
        t1=[0]*32
        t2=[0]*32
        c=0
        tempA=a
        tempB=b
        if tempA<0:
            tempA=-tempA
        if tempB<0:
            tempB=-tempB
        while tempA:
            t1[c]=tempA&1
            tempA>>=1
            c+=1
        c=0
        while tempB:
            t2[c]=tempB&1
            tempB>>=1
            c+=1
        if a<0:
            for i in range(32):
                if t1[i]==0:
                    t1[i]=1
                else:
                    t1[i]=0
            carry=1
            for i in range(32):
                x=carry+t1[i]
                if x==0:
                    carry=0
                elif x==1:
                    carry=0
                    t1[i]=1
                else:
                    carry=1
                    t1[i]=0
        if b<0:
            for i in range(32):
                if t2[i]==0:
                    t2[i]=1
                else:
                    t2[i]=0
            carry=1
            for i in range(32):
                x=carry+t2[i]
                if x==0:
                    carry=0
                elif x==1:
                    carry=0
                    t2[i]=1
                else:
                    carry=1
                    t2[i]=0
        carry=0
        res1=0
        temp=0
        print(t1,t2)
        for i in range(31):
            x=carry+t1[i]+t2[i]
            if x==2:
                temp=0
                carry=1
            elif x==1:
                temp=1
                carry=0
                res1+=1<<(i)
            elif x==0:
                temp=0
                carry=0
            else:
                temp=1
                carry=1
                res1+=1<<(i)
        res1=res1-2**(31)*temp
        return res1