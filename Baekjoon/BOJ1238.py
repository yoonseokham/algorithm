import sys
import heapq


def Dijkstra(cost_arr,graph,start:int,end:int):
    pq=[[0,start]]
    cost_arr[start][start]=0
    while pq:
        curCost,curNode=heapq.heappop(pq)
        for nextNode,cost in graph[curNode]:
            if cost_arr[start][nextNode]> curCost+cost:
                 cost_arr[start][nextNode]=curCost+cost
                 heapq.heappush(pq,[cost_arr[start][nextNode],nextNode])
if __name__=="__main__":
    n,m,x=map(int,input().split())
    graph=[[] for  i in range(n+1)]
    MAX=(999999999)
    cost_arr=[ [ MAX for i in range(n+1)] for i in range(n+1)]
    for i in range(m):
        start,end,cost=map(int,input().split())
        graph[start].append((end,cost))
    for i in range(1,n+1):
        Dijkstra(cost_arr,graph,i,x)
    print(max([cost_arr[i][x]+cost_arr[x][i] for i in range(1,n+1)]))
