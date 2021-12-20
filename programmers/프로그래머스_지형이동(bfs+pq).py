import heapq
import collections
def solution(land, height):
    answer = 0
    n = len(land)
    segCheck = lambda i,j : True if 0 <= i < n and 0<= j < n else False
    def bfs_with_pq():
        nonlocal answer
        Point = collections.namedtuple('Point','cost index jndex')
        visit = [[False for _ in range(n)] for _ in range(n)]
        pq = [Point(cost=0,index=0,jndex=0)]
        didj = list(zip((-1,0,1,0),(0,1,0,-1)))
        while pq:
            curPoint = heapq.heappop(pq)
            if not visit[curPoint.index][curPoint.jndex]:
                visit[curPoint.index][curPoint.jndex] = True
                answer += curPoint.cost
                for i,j in didj:
                    newI = curPoint.index + i
                    newJ = curPoint.jndex + j
                    if segCheck(newI,newJ) and not visit[newI][newJ]:
                        diff = abs(land[newI][newJ]-land[curPoint.index][curPoint.jndex])
                        if diff <= height:
                            newCost = 0
                        else:
                            newCost = diff
                        newPoint = Point(newCost,newI,newJ)
                        heapq.heappush(pq,newPoint)
    bfs_with_pq()
    return answer
