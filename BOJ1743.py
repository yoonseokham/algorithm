import sys
sys.setrecursionlimit(100000)
rows,cols,n=map(int,input().split())
arr = [ [0 for i in range(cols)] for i in range(rows)]
visit = [ [0 for i in range(cols)] for i in range(rows)]
depth=0
for i in range(n):
    a,b=map(int,input().split())
    arr[a-1][b-1]=1
def segCheck(i,j,rows,cols):
    if i>=0 and i<rows and j>=0 and j<cols:
        return True
    return False

def DFS(curI,curJ,rows,cols):
    global visit,arr,depth
    for i in range(4):
        NextI=curI+int('0121'[i]) -1
        NextJ=curJ+int('1210'[i]) -1
        if segCheck(NextI,NextJ,rows,cols) and arr[NextI][NextJ]==1 and visit[NextI][NextJ]==0:
            depth+=1
            visit[NextI][NextJ]=depth
            DFS(NextI,NextJ,rows,cols)

Max=-1
for i in range(rows):
    for j in range(cols):
        if arr[i][j]==1 and visit[i][j]==0:
            depth=1
            visit[i][j]=1
            DFS(i,j,rows,cols)
            Max=max(Max,depth)
print(Max)
