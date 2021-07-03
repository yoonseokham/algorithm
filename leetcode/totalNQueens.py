class Solution:
    def totalNQueens(self, n: int) -> int:
        PlacedQueen=set()
        answer=0
        def QueenPlaceAble(row:int,column:int)->bool:
            for i,j in PlacedQueen:
                if row==i or column==j or abs(row-i)==abs(column-j):
                    return False
            return True
        
        def BackTrack(row:int)->None:
            nonlocal answer
            if row==n:
                answer+=1
            for j in range(n):
                if QueenPlaceAble(row,j):
                    PlacedQueen.add((row,j))
                    BackTrack(row+1)
                    PlacedQueen.remove((row,j))
        BackTrack(0)
        return answer
        
