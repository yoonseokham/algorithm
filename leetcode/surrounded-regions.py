class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        di = (-1,0,1,0)
        dj = (0,1,0,-1)
        rows,columns = len(board),len(board[0])
        segCheck = lambda i,j :True if 0 <=i<rows and 0<=j<columns else False
        visit=[[False for _ in range(columns)] for _ in range(rows)]
        def DFS(index,jndex):
            visit[index][jndex] = True
            for i,j in zip(di,dj):
                nextIndex = index + i
                nextJndex = jndex + j
                if segCheck(nextIndex,nextJndex):
                    if not visit[nextIndex][nextJndex] and board[nextIndex][nextJndex] == 'O':
                        DFS(nextIndex,nextJndex)
        
        for i in range(columns):
            if board[0][i] == 'O':
                DFS(0,i)
        for i in range(columns):
            if board[rows-1][i] == 'O':
                DFS(rows-1,i)
        for i in range(rows):
            if board[i][0] == 'O':
                DFS(i,0)      
        for i in range(rows):
            if board[i][columns-1] == 'O':
                DFS(i,columns-1)
        for i in range(rows):
            for j in range(columns):
                if not visit[i][j] and board[i][j] == 'O':
                    board[i][j] = 'X'
                    
        
                                                
