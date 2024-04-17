# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def smallestFromLeaf(self, root):
        """
        :type root: TreeNode
        :rtype: str
        """
        self.ans = "~"
        self.dfs(root,[])
        return self.ans
    def dfs(self, node, A):
        if node:
            A.append(chr(node.val + ord('a')))
            if not node.left and not node.right:
                self.ans = min(self.ans, ''.join(reversed(A)))
                A.pop()
                return
            self.dfs(node.left,A)
            self.dfs(node.right,A)
            A.pop()
            return
