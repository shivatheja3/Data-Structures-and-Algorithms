 #User function Template for python3
 
class Solution:
    
    # arr[] : the input array
    # N : size of the array arr[]
    
    #Function to return length of longest subsequence of consecutive integers.
    def findLongestConseqSubseq(self,arr, N):
        #code here
        if N == 1:
            return 1
        if N == 0:
            return 0
        arr.sort()
        maxlength = 1
        currlength = 1
        #print(arr)
        
        for i in range(N-1):
            
            if arr[i] + 1 == arr[i+1]:
                currlength+= 1
            elif arr[i] == arr[i+1]:
                continue
            else:
                maxlength = max(currlength, maxlength)
                currlength=1
            # print(arr[i],arr[i+1],currlength)
                
        maxlength = max(currlength, maxlength)        
        
        return maxlength

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        n=int(input())
        a = list(map(int, input().strip().split()))
        print(Solution().findLongestConseqSubseq(a,n))
# } Driver Code Ends