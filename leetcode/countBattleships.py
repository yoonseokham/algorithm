class Solution:
    def dfs(self,visit,board,index,jndex):
        visit[index][jndex]=True
        for k in range(4):
            newI=index+int("0121"[k])-1
            newJ=jndex+int("1210"[k])-1
            if 0<=newI<len(board) and 0<=newJ<len(board[0]) and not visit[newI][newJ] and board[newI][newJ]=='X':
                self.dfs(visit,board,newI,newJ)
    def countBattleships(self, board: List[List[str]]) -> int:
        count=0
        visit=[[False for i in range(len(board[0]))] for i in range(len(board))]
        for i in range(len(board)):
            for j in range(len(board[0])):
                if visit[i][j]==False and board[i][j]=='X':
                    count+=1
                    self.dfs(visit,board,i,j)
        return count
