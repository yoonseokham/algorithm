import sys
import heapq
from collections import defaultdict
if __name__ == "__main__":
    numOfCity=int(input())
    numOfBus=int(input())
    MAX=(1001)
    graph=defaultdict(list)
    min_graph=defaultdict(lambda:MAX*MAX)
    for _ in range(numOfBus):
        start,end,cost=map(int,sys.stdin.readline().rstrip().split())
        min_graph[(start,end)]=min(min_graph[(start,end)],cost)
    for (start,end),cost in min_graph.items():
        graph[start].append((end,cost))
    def dijkstra(start,end):
        visit=[MAX*MAX*MAX]*MAX
        visit[start]=0
        pq=[(visit[start],start)]
        while pq:
            _,curNode=heapq.heappop(pq)
            for node,cost in graph[curNode]:
                if visit[node]>cost+visit[curNode]:
                    visit[node]=cost+visit[curNode]
                    heapq.heappush(pq,(-visit[node],node))
        return visit[end]
    print(dijkstra(*map(int,input().split())))
                    
