# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.sum = 0
        self.dfs(root)
        return self.sum
    def dfs(self,node,num=0):
        if node:
            num = num*10 + node.val
            if not node.right and not node.left:
                self.sum+=num
                num/=10
                return
            self.dfs(node.right,num)
            self.dfs(node.left,num)
            num/=10
            return
