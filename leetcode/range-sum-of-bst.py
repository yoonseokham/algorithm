# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfRangeDFS(self, root, low, high):
        visited = []

        def dfs(root):
            if root:
                if low <= root.val <= high:
                    visited.append(root.val)
                if root.val > low:
                    dfs(root.left)
                if root.val < high:
                    dfs(root.right)

        dfs(root)
        return sum(visited)

    def rangeSumBST(self, root: Optional[TreeNode], low: int,
                    high: int) -> int:
        return self.sumOfRangeDFS(root, low, high)
