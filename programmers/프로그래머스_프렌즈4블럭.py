from collections import deque
def checker(i:int,j:int,game_board:list)->bool:
    return len(set([game_board[i][j],game_board[i+1][j],game_board[i][j+1],game_board[i+1][j+1]]))==1 and game_board[i][j]!=0
def solution(m, n, board):
    answer = 0
    game_board=[[board[j][i] for i in range(n)] for j in range(m)]
    while True:
        new_board=[[0 for i in range(n)] for i in range(m)]
        temp_board=[[0 for i in range(n)] for i in range(m)]
        for i in range(m-1):
            for j in range(n-1):
                if checker(i,j,game_board):
                    temp_board[i][j]="X"
                    temp_board[i][j+1]="X"
                    temp_board[i+1][j]="X"
                    temp_board[i+1][j+1]="X"
        for j in range(n):
            dq=deque([])
            cur=m-1
            for i in range(m):
                if temp_board[i][j]!="X":
                    dq.appendleft(game_board[i][j])
            while dq:
                a=dq.popleft()
                new_board[cur][j]=a
                cur-=1
        if game_board==new_board:
            break
        game_board=new_board
    for i in game_board:
        for j in i:
            if j!=0:
                answer+=1
    return n*m-answer
