import collections


class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int,
                  destination: int) -> bool:
        visited = set([source])
        graph = collections.defaultdict(list)

        for start, end in edges:
            graph[start].append(end)
            graph[end].append(start)

        def dfs(node):
            if destination in visited:
                return
            for adjacent_node in graph[node]:
                if not (adjacent_node in visited):
                    visited.add(adjacent_node)
                    dfs(adjacent_node)

        dfs(source)
        return destination in visited
