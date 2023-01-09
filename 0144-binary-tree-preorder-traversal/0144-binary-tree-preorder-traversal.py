# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        a=[]
        res=[]
        p=root
        top=-1
        while(p):
            res.append(p.val)
            a.append(p)
            p=p.left
        while(len(a)):
            p=a[-1]
            if(p.right):
                p=a.pop()
                p=p.right;
                res.append(p.val)
                a.append(p)
                while(p):
                    p=p.left
                    if(p):
                        res.append(p.val)
                        a.append(p)
            else:
                a.pop()
        return res
    
                
            
            
        