from collections import deque
from collections import Counter
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        sucess=[False]
        def BackTrack(s,visit,sucess,x,y):
            if s==word: sucess[0]=True
            elif sucess[0]==False:
                for i in range(4):
                    newI=x+int("1210"[i])-1
                    newJ=y+int("0121"[i])-1
                    if 0<=newI<len(board) and 0<=newJ<len(board[0]) and (newI,newJ) not in visit and board[newI][newJ]==word[len(s)]:
                        visit.add((newI,newJ))
                        BackTrack(s+board[newI][newJ],visit,sucess,newI,newJ)
                        visit.remove((newI,newJ))
        a=Counter(word)
        b=Counter()
        for x,i in enumerate(board):
            for y,j in enumerate(i):
                b.update(i)
        temp=b.items()
        for i,j in a.items():
            if not (i in b and b[i]>=j): return False
        for x,i in enumerate(board):
            for y,j in enumerate(i):
                if j==word[0] and sucess[0]==False:
                    visit=set()
                    visit.add((x,y))
                    BackTrack(j,visit,sucess,x,y)
                    if sucess[0]: return True
        return False
