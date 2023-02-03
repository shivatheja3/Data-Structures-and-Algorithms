class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        l=[]
        for i in range(numRows):
            l.append([])
        i=0
        j=0
        while(j<len(s)):
            for i in range(numRows):
                if j==len(s):
                    break
                l[i].append(str(s[j]))
                j+=1
            for i in range(numRows-2,0,-1):
                if j==len(s):
                    break
                l[i].append(str(s[j]))
                j+=1
        res=""
        for i in range(len(l)):
            for j in range(len(l[i])):
                res+=l[i][j]
            
        # print(l)
        return res
        
        