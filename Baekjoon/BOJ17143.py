def mover(pool,r,c,s,Direact:tuple,z,R,C):
    temp_r=r
    temp_c=c
    for i in range(s):
        if temp_r+Direact[0]>=R or temp_r+Direact[0]<0:
            Direact[0]*=-1
        if temp_c+Direact[1]>=C or temp_c+Direact[1]<0:
            Direact[1]*=-1
        temp_r+=Direact[0]
        temp_c+=Direact[1]
    if pool[temp_r][temp_c]==0 or pool[temp_r][temp_c][2]<z:
        pool[temp_r][temp_c]=[s,Direact,z]

if __name__=="__main__":
    R,C,M=map(int,input().split())
    shark=0
    pool=[[ 0 for i in range(C)] for i in range(R)]
    moving=[[ 0 for i in range(C)] for i in range(R)]
    moveDireact={1:[-1,0],2:[1,0],3:[0,1],4:[0,-1]}
    for i in range(M):
        r,c,s,d,z=map(int,input().split())
        pool[r-1][c-1]=[s,moveDireact[d][:],z]
    for fisher in range(0,C):
        moving=[[ 0 for i in range(C)] for i in range(R)]

        for k in range(R):
            if pool[k][fisher]!=0:
                shark+=pool[k][fisher][2]
                pool[k][fisher]=0
                break

        for i in range(R):
            for j in range(C):
                if pool[i][j]!=0:
                    mover(moving,i,j,*pool[i][j],R,C)
        pool=moving
    print(shark)
