import sys
import collections
import heapq


def stdin_list():
    return map(int,sys.stdin.readline().split())


def dijkstra(start, tree):
    MAX = 999999999
    dp = { i:MAX for i in tree.keys()}
    dp[start] = 0
    pq = [(0,start)]
    while pq:
        cost, curNode = heapq.heappop(pq)
        for nextNode, nextCost in tree[curNode]:
            if dp[nextNode] > dp[curNode] + nextCost:
                dp[nextNode] = dp[curNode] + nextCost
                heapq.heappush(pq,(dp[nextNode],nextNode))
    return dp


if __name__ == '__main__':
    n,m = stdin_list()
    tree = collections.defaultdict(list)
    dp_list = collections.defaultdict(lambda:False)
    start_list = []
    end_list = []

    for _ in range(1,n):
        nodeA, nodeB, cost = stdin_list()
        tree[nodeA].append((nodeB,cost))
        tree[nodeB].append((nodeA,cost))

    for _ in range(m):
        start, end = stdin_list()
        start_list.append(start)
        end_list.append(end)
        if not dp_list[start]:
            dp_list[start] = dijkstra(start, tree)

    for start, end in zip(start_list, end_list):
        print(dp_list[start][end])
