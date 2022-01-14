class Solution:
    def is3X3Valid(self, board, index, jndex):
        grid_i = 3*(index//3)
        grid_j = 3*(jndex//3)
        number = set()
        for i in range(grid_i,grid_i+3):
            for j in range(grid_j,grid_j+3):
                
                if board[i][j] in number:
                    return False
                if board[i][j] != '.':
                    number.add(board[i][j])
        return True
    def isVerticalValid(self, board, index, jndex):
        number = set()
        for i in range(9):
            if board[i][jndex] in number:
                return False
            if board[i][jndex] != '.':
                number.add(board[i][jndex])
        return True
    def isHorizenValid(self, board, index, jndex):
        number = set()
        for j in range(9):
            if board[index][j] in number:
                return False
            if board[index][j] != '.':
                number.add(board[index][j])
        return True
    
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        validators = \
        [
            self.is3X3Valid,
            self.isVerticalValid,
            self.isHorizenValid,
        ]
        for i in range(9):
            for j in range(9):
                for validator in validators:
                    if not validator(board, i, j):
                        return False
        return True
        
