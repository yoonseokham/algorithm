import collections


class Solution:
    def totalNQueens(self, n: int) -> int:
        Point = collections.namedtuple('Point', 'i j')
        QueenLocation = set()
        answer = 0

        def isKillable(p1, p2):
            condition = (
                p1.j == p2.j,
                abs(p1.i - p2.i) == abs(p1.j - p2.j),
            )
            return any(condition)

        def isQueenAddable(point):
            for queenPoint in QueenLocation:
                if isKillable(point, queenPoint):
                    return False
            return True

        def dfs(i=0):
            nonlocal answer
            if len(QueenLocation) == n:
                answer += 1
                return
            for j in range(n):
                curPoint = Point(i, j)
                if isQueenAddable(curPoint):
                    QueenLocation.add(curPoint)
                    dfs(i + 1)
                    QueenLocation.remove(curPoint)

        dfs()
        return answer
