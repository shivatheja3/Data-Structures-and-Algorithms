class Solution(object):
    def strStr(self, ha, ne):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(ne)>len(ha):
            return -1
        elif len(ne)==len(ha):
            if ne!=ha:
                return -1
            return 0
        p=7
        hss=0
        hs=0
        for i in range(len(ne)):
            hss+=(ord(ne[i])-96)*int(p**(i+1))
            hs+=(ord(ha[i])-96)*int(p**(i+1))
        if hss==hs:
            return 0
        for i in range(len(ne),len(ha),1):
            hs-=(ord(ha[i-len(ne)])-96)*(p**(i-len(ne)+1))
            hs+=(ord(ha[i])-96)*(p**(i+1))
            if hss==hs//(p**(i-len(ne)+1)):
                return i-len(ne)+1
        return -1
        