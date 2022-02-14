class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs_closure(curI, curJ):
            answer = False
            didj=list(zip((-1,0,1,0),(0,1,0,-1)))
            if board[curI][curJ] != word[0]:
                return False
            visit = [[False]*len(board[0]) for _ in range(len(board))]
            visit[curI][curJ] = True
            def dfs(curI, curJ, index=0):
                nonlocal answer
                if len(word)-1 == index:
                    answer = True
                    return
                for i,j in didj:
                    newI = curI + i
                    newJ = curJ + j
                    if 0 <= newI < len(board) and 0<= newJ < len(board[0]):
                        if not visit[newI][newJ] and word[index+1] == board[newI][newJ]:
                            visit[newI][newJ] = True
                            dfs(newI, newJ, index+1)
                            visit[newI][newJ] = False
            dfs(curI, curJ)
            return answer
        
        for i in range(len(board)):
            for j in range(len(board[i])):
                if dfs_closure(i, j):
                    return True
        return False
                    
            
