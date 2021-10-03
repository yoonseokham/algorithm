def solution(game_board, table):
    n = len(game_board)
    def return_piece_list(isGameBoard):
        piece_data = 0 if isGameBoard else 1
        board =  game_board if isGameBoard else table
        visit = [[False for _ in range(n)] for _ in range(n)]
        di=[-1,0,1,0]
        dj=[0,1,0,-1]
         
        def dfs(index,jndex):
            temp.append([index,jndex])
            visit[index][jndex]=True
            for i,j in zip(di,dj):
                newI=i+index
                newJ=j+jndex
                if 0<=newI<n and 0<=newJ<n and not visit[newI][newJ] and board[newI][newJ] == piece_data:
                    dfs(newI,newJ)
        
        piece_list=[]
        for i in range(n):
            for j in range(n):
                if board[i][j] == piece_data and not visit[i][j]:
                    temp=[]
                    dfs(i,j)
                    piece_list.append(temp)
        return piece_list
    
    def rotate_piece_list_and_normalize(piece_list):
        real_list=[]
        def normalize(piece):
            small_i,small_j=sorted(piece)[0]
            return sorted([ [i-small_i,j-small_j] for i,j in sorted(piece)])

        def rotate_piece(piece):
            return sorted([ [j,-i] for i,j in piece])

        for piece in piece_list:
            one = normalize(piece)
            two = normalize(rotate_piece(one))
            three = normalize(rotate_piece(two))
            four = normalize(rotate_piece(three))
            real_list.append([one,two,three,four])
        return real_list
                
    game_piece_list=rotate_piece_list_and_normalize(return_piece_list(True))
    table_piece_list=rotate_piece_list_and_normalize(return_piece_list(False))
    sum=0
    
    def isSame(game_piece,table_piece):
        for i in game_piece:
            for j in table_piece:
                if i==j:
                    return True
        return False
    
    for game_piece in game_piece_list[:]:
        for table_piece in table_piece_list[:]:
            if isSame(game_piece,table_piece) and game_piece in game_piece_list and table_piece in table_piece_list:
                game_piece_list.remove(game_piece)
                table_piece_list.remove(table_piece)
                sum+=len(game_piece[0])    
    return sum
