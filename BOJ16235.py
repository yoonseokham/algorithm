import sys
import heapq
n,m,k=map(int,input().split())

food=[[5 for i in range(n)] for i in range(n)]
s2d2=[[ 0 for i in range(n)] for i in range(n)]
tree_age=[[[] for i in range(n)] for i in range(n)]



for i in range(n):
    line=sys.stdin.readline().rstrip().split()
    for j in range(len(line)):
        s2d2[i][j]=int(line[j])
for i in range(m):
    line=sys.stdin.readline().rstrip().split()
    x=int(line[0])-1
    y=int(line[1])-1
    age=int(line[2])
    tree_age[x][y].append(age)
cnt=0
for i in range(n):
    for j in range(n):
        tree_age[i][j].sort()
for years in range(k):
    dead=[[0 for i in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            if len(tree_age[i][j])!=0:
                temp=[]
                while tree_age[i][j]:
                    top=tree_age[i][j].pop()
                    if top<=food[i][j]:
                        food[i][j]-=top
                        temp.append(top+1)
                    else:
                        dead[i][j]+=int(top/2)
                temp.reverse()
                tree_age[i][j]=temp
            food[i][j]+=dead[i][j]+s2d2[i][j]
    for i in range(n):
        for j in range(n):
            for l in tree_age[i][j]:
                if l%5==0:
                    for u in range(8):
                        NewI=i+int("00122210"[u])-1
                        NewJ=j+int("12221000"[u])-1
                        if NewI>=0 and NewI<n and NewJ>=0 and NewJ<n:
                            tree_age[NewI][NewJ].append(1)
    if years==k-1:
        for i in range(n):
            for j in range(n):
                cnt+=len(tree_age[i][j])

print(cnt)
