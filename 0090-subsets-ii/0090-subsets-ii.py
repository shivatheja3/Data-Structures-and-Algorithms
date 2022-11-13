class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res=[[]]
        nums.sort()
        for i in range(1,1<<len(nums)):
            x=i
            c1=0
            temp=[]
            while x:
                if x&1:
                    temp.append(nums[c1])
                c1+=1
                x>>=1
            if temp not in res:
                res.append(temp)
        return res
        
        
# int n=nums.size();
#         vector<vector<int>> res{{}};
#         for(int i=1;i<(1<<n);++i){
#             int x=i,c1=0;
#             vector<int> t;
#             while(x){
#                 if(x&1){
#                     t.push_back(nums[c1]);
#                 }
#                  ++c1;
#                  x>>=1;
#             }
#             res.push_back(t);