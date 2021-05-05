def segCheck(index:int,jndex:int,n:int)->bool:
    return (0<=index<n and 0<=jndex<n)
def direactionCal(index:int,jndex:int,Nindex:int,Njndex:int)->str:
    if index==Nindex:
        return "-"
    return "|"
def StraightOrCurve(index:int,jndex:int,Nindex:int,Njndex:int,direaction:str)->bool:
    return direaction=="0" or direactionCal(index,jndex,Nindex,Njndex)==direaction  
def dpIniter(board:list,dp:list,index:int,jndex:int,n:int,direaction:str)->int:
    for i in range(4):
        Nindex=index+int("0121"[i])-1
        Njndex=jndex+int("1210"[i])-1
        if segCheck(Nindex,Njndex,n) and board[Nindex][Njndex]==0:
            NextDireaction=direactionCal(index,jndex,Nindex,Njndex)
            Straight=StraightOrCurve(index,jndex,Nindex,Njndex,direaction)
            if Straight and dp[Nindex][Njndex]>=dp[index][jndex]+100:
                dp[Nindex][Njndex]=dp[index][jndex]+100
                dpIniter(board,dp,Nindex,Njndex,n,NextDireaction) 
            elif not Straight and dp[Nindex][Njndex]>=dp[index][jndex]+600:
                dp[Nindex][Njndex]=dp[index][jndex]+600
                dpIniter(board,dp,Nindex,Njndex,n,NextDireaction)
def solution(board):
    answer = 0
    n=len(board)
    dp=[[9999999 for i in range(n)] for i in range(n)]
    dp[0][0]=0
    dpIniter(board,dp,0,0,n,"0")
    return dp[n-1][n-1]
