import sys
import heapq
if __name__ == "__main__":
    numOfCity=int(input())
    numOfBus=int(input())
    MAX=(1001)
    graph=[[-1]*MAX for _ in range(MAX)]
    for _ in range(numOfBus):
        start,end,cost=map(int,sys.stdin.readline().rstrip().split())
        if graph[start][end]!=-1:
            graph[start][end]=min(cost,graph[start][end])
        else: graph[start][end]=cost
    def dijkstra(start,end):
        visit=[MAX*MAX*MAX]*MAX
        visit[start]=0
        pq=[(visit[start],start)]
        while pq:
            _,curNode=heapq.heappop(pq)
            for node,cost in enumerate(graph[curNode]):
                if cost!=-1 and visit[node]>cost+visit[curNode]:
                    visit[node]=cost+visit[curNode]
                    heapq.heappush(pq,(-visit[node],node))
        return visit[end]
    print(dijkstra(*map(int,input().split())))
                    
