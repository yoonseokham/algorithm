n,m=map(int,input().split())

visit=[False]*n
vector=[]
def BackTrack(n:int,m:int,visit:list,vector:list):
    if m==len(vector): 
        for i in vector:
            print(i+1,end=" ")
        print()
    else:
        for i in range(0,n):
            if not visit[i]:
                visit[i]=True
                vector.append(i)
                BackTrack(n,m,visit,vector)
                vector.pop()
                visit[i]=False
BackTrack(n,m,visit,vector)
