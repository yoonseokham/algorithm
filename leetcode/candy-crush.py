import copy
import collections
class Solution:
    
    def same_finder(self, index, jndex, board, di, dj):
        rows, cols = len(board), len(board[0])
        visit = [[False]* cols for _ in range(rows)]
        visit[index][jndex] = True
        answer = [(index,jndex)]
        def dfs(curI, curJ):
            newI = di + curI
            newJ = dj + curJ
            if 0<= newI < rows and 0<= newJ < cols:
                if not visit[newI][newJ] and board[newI][newJ] == board[curI][curJ]:
                    visit[newI][newJ] = True
                    answer.append((newI,newJ))
                    dfs(newI,newJ)
        dfs(index,jndex)
        return answer
    
    def zero_maker(self, board):
        all_zero = []
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]:
                    horizontal = self.same_finder(i, j, board, 1, 0)
                    vertical = self.same_finder(i, j, board, 0, 1)
                    for zeros in (horizontal, vertical):
                        if len(zeros) >= 3:
                            all_zero += zeros
                            
        for i,j in set(all_zero):
            board[i][j] = 0
                            
    def gravity(self, board):
        rows, cols = len(board), len(board[0])
        new_board = [[0]* cols for _ in range(rows)]
        for j in range(cols):
            q = collections.deque([])
            k = 1
            for i in range(rows-1,-1,-1):
                if board[i][j]:
                    q.append(board[i][j])
            while q:
                value = q.popleft()
                new_board[rows - k][j] = value
                k += 1         
        return new_board
    
    def candyCrush(self, board: List[List[int]]) -> List[List[int]]:
        pre_board = board[:][:]
        while True:
            self.zero_maker(board)
            board = self.gravity(board)
            if pre_board == board:
                return board
            pre_board = board[:][:]
