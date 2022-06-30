import collections
class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        graph = collections.defaultdict(list)

        for start, end in paths:
            graph[start].append(end)

        def travelByDfs(node):
            if graph[node]:
                return travelByDfs(graph[node][0])
            else:
                return node

        result = travelByDfs(start)
        return result
