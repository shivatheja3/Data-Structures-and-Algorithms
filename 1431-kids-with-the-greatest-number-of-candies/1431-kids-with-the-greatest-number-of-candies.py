class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """
        res=[]
        for i in range(len(candies)):
            candies[i]+=extraCandies
            if candies[i]>=max(candies):
                res.append(True)
            else:
                res.append(False)
            candies[i]-=extraCandies
        return res