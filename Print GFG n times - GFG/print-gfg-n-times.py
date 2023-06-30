#User function Template for python3

class Solution:
    def func(self,n):
        if n==0:
            return
        print("GFG",end=" ")
        self.func(n-1)
    def printGfg(self, n):
        self.func(n)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        ob.printGfg(N)
        print()
# } Driver Code Ends