import heapq
MAX=2000000000
def Dijkstra(start:int,end:int,n:int,v:list)->int:
    pq=[[0,start]]
    dp=[MAX for i in range(n+1)]
    dp[start]=0
    while pq:
        curCost,curNode=heapq.heappop(pq)
        if curCost>dp[curNode]:
            continue
        for i in v[curNode]:
            nextNode,nextNodeCost=i
            if dp[nextNode]>curCost+nextNodeCost:
                dp[nextNode]=curCost+nextNodeCost
                heapq.heappush(pq,[curCost+nextNodeCost,nextNode])
    return dp[end]
    pass
def solution(n, s, a, b, fares):
    answer = 0
    v=[[] for i in range(n+1)]
    for i in  fares:
        start,end,cost=i
        v[start].append([end,cost])
        v[end].append([start,cost])
    answer=Dijkstra(s,a,n,v)+Dijkstra(s,b,n,v)
    for i in range(1,n+1):
        if i!=s:
            answer=min(Dijkstra(s,i,n,v)+Dijkstra(i,b,n,v)+Dijkstra(i,a,n,v),answer) 
    return answer
