import collections
class Solution:
    def BFS(self, n):
        nextStep = [ i*i for i in range(1,int(sqrt(n))+1)]
        q = collections.deque([(n,0)])
        visit = collections.defaultdict(lambda:99999)
        visit[n] = 0
        while q:
            curNum, curStep = q.popleft()
            if curNum == 0:
                return curStep
            else:
                for i in nextStep:
                    if curNum - i >= 0 and visit[curNum-i] > curStep + 1:
                        visit[curNum-i] = curStep + 1
                        q.append((curNum-i,curStep+1))
                    
    def numSquares(self, n: int) -> int:
        return self.BFS(n)
