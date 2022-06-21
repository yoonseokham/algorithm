class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        class inorderTravel:
            def __init__(self):
                self.nodes = []
                self.answer = 10**5 + 1

            def __call__(self, node):
                def dfs(node):
                    if (node is None):
                        return
                    dfs(node.left)
                    self.nodes.append(node.val)
                    dfs(node.right)

                dfs(node)
                for i in range(len(self.nodes) - 1):
                    self.answer = min(self.answer,
                                      abs(self.nodes[i] - self.nodes[i + 1]))
                return self.answer

        solve = inorderTravel()
        return solve(root)
