import heapq
class Solution:
    def BFS(self, n):
        nextStep = [ i*i for i in range(1,int(sqrt(n))+1)]
        pq = [(0,n)]
        visit = collections.defaultdict(lambda:99999)
        visit[n] = 0
        while pq:
            curStep, curNum = heapq.heappop(pq)
            if curNum == 0:
                return curStep
            else:
                for i in nextStep:
                    if curNum - i >= 0 and visit[curNum-i] > curStep + 1:
                        visit[curNum-i] = curStep + 1
                        heapq.heappush(pq,(curStep+1,curNum-i))
                    
    def numSquares(self, n: int) -> int:
        return self.BFS(n)
