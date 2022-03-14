import collections
class Solution:
    def BFS(self, n):
        nextStep = [ i*i for i in range(1,int(sqrt(n))+1)]
        current_q = set([n])
        answer = 0
        while True:
            next_q = set()
            for i in current_q:
                if not i:
                    return answer
                for j in nextStep:
                    if i-j >= 0:
                        next_q.add(i-j)
            current_q = next_q
            answer += 1
    def numSquares(self, n: int) -> int:
        return self.BFS(n)
