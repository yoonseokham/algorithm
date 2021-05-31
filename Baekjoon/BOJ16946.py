from collections import deque
def zeroCounter(maze:list,visit:list,index:int,jndex:int,n:int,m:int,count:list,check:set()):
    q=deque([[index,jndex]])
    visit[index][jndex]=True
    while q:
        index,jndex=q.popleft()
        check.add((index,jndex))
        count[0]+=1
        for i in range(4):
            newI=index+int("0121"[i])-1
            newJ=jndex+int("1210"[i])-1
            if 0<=newI<n and 0<=newJ<m and visit[newI][newJ]==False and maze[newI][newJ]==0:
                visit[newI][newJ]=True
                q.append([newI,newJ])
def show(a:list):
    for i in range(len(a)):
        for j in range(len(a[0])):
            print( a[i][j]%10,end="")
        print()
if __name__=="__main__":
    n,m=map(int,input().split())
    maze=[[0]*m for i in range(n)]
    answer=[[0]*m for i in range(n)]
    printer=[[0]*m for i in range(n)]
    visit=[[False]*m for i in range(n)]
    for i in range(n):
        temp=input().strip()
        for j in range(len(temp)):
            maze[i][j]=int(temp[j])
            if maze[i][j]==1:
                 printer[i][j]=1
    for i in range(n):
        for j in range(m):
            if maze[i][j]==0 and visit[i][j]==False:
                count=[0]
                check=set()
                zeroCounter(maze,visit,i,j,n,m,count,check)
                visited=set()
                for x,y in check:
                    answer[x][y]=count[0]
                    for a in range(0,8,2):
                        newI=x+int("00122210"[a])-1
                        newJ=y+int("12221000"[a])-1
                        if  0<=newI<n and 0<=newJ<m and maze[newI][newJ]==1 and (newI,newJ) not in visited:
                            visited.add((newI,newJ))
                            printer[newI][newJ]+=count[0]
    show(printer)
