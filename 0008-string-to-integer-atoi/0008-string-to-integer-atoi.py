class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        sign=['-','+']
        nums=['1','2','3','4','5','6','7','8','9','0']
        space=[' ']
        res=0
        v=1
        for i in range(len(s)):
            # print(res)
            if s[i] in space:
                continue
            elif s[i] in sign:
                if s[i]=='-':
                    v=0
                sign=[]
                space=[]
            elif s[i] in nums:
                res=res*10+int(s[i])
                sign=[]
                space=[]
            else:
                break
        if v==0:
            res=-res
        if(res>-2147483648 and res<2147483647):
            return res
        elif(res<=-2147483648):
            return -2147483648
        else:
            return 2147483647
                
        