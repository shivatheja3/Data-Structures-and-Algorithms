class Solution(object):
    def findLongestChain(self, pairs):
        pairs.sort(key=lambda x:x[1])
        # print(pairs)
        ans = 0
        temp = -1001
        for i in range(0, len(pairs)):
            if pairs[i][0] > temp:
                ans += 1
                temp = pairs[i][1]
        return ans
