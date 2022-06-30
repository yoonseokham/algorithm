import collections


class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        graph = collections.defaultdict(list)
        parentNode = [i for i in range(n)]
        union = collections.defaultdict(list)
        answer = 0

        def getParent(node: int) -> int:
            if node == parentNode[node]:
                return node
            else:
                parentNode[node] = getParent(parentNode[node])
                return parentNode[node]

        def unionXY(x: int, y: int):
            x = getParent(x)
            y = getParent(y)
            if x > y:
                parentNode[x] = y
            else:
                parentNode[y] = x

        for start, end in edges:
            graph[start].append(end)
            graph[end].append(start)
            unionXY(start, end)

        for node, parent in enumerate(parentNode):
            union[getParent(parent)].append(node)
        union_with_nodes = [len(nodes) for parent, nodes in union.items()]
        dp = list(reversed([len(nodes) for parent, nodes in union.items()]))
        for i in range(1, len(dp)):
            dp[i] = dp[i - 1] + dp[i]
        dp.reverse()
        for i in range(len(dp) - 1):
            answer += union_with_nodes[i] * dp[i + 1]
        return answer
