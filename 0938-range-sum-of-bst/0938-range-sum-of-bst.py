# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rangeSumBST(self, root, low, high):
        """
        :type root: TreeNode
        :type low: int
        :type high: int
        :rtype: int
        """
        p=root
        k=root
        st=[]
        a1=[]
        a1.append(p.val)
        st.append(p)
        while(len(st)):
            k=st[0]
            st.remove(st[0])
            if k.left is not None:
                st.append(k.left)
                a1.append(k.left.val)
            if k.right is not None:
                st.append(k.right)
                a1.append(k.right.val)
        sum1=0
        for i in range(len(a1)):
            if a1[i]>=low and a1[i]<=high:
                sum1+=a1[i]
                
        return sum1
        