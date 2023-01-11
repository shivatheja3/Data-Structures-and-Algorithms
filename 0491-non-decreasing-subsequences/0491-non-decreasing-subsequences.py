class Solution(object):
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res=[]
        # nums.sort()
        for i in range(1,1<<len(nums)):
            x=i
            c1=0
            temp=[]
            while x:
                if x&1:
                    if len(temp)>0:
                        if temp[-1]<=nums[c1]:
                            temp.append(nums[c1])
                        else:
                            break
                    else:
                        temp.append(nums[c1])

                c1+=1
                x>>=1
            if temp not in res and len(temp)>1:
                res.append(temp)
        return res
        