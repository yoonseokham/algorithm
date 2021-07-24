import copy
if __name__ == "__main__":
    n,m=map(int,input().split())
    direactionList=list(zip([0,-1,-1,-1,0,1,1,1],[-1,-1,0,1,1,1,0,-1]))
    land=[[0]*n for _ in range(n)]
    for i in range(n):
        temp=input().rstrip().split()
        for j in range(len(temp)):
            land[i][j]=int(temp[j])
    command=[tuple(map(int,input().split())) for _ in range(m)]
    cloudLocation=[(n-1,0),(n-1,1),(n-2,0),(n-2,1)]

    def cloudMover(commandIndex):
        def cloudPush(i,j,move,direaction):
            newI=(i+move* direactionList[direaction-1][0]+n*1000000)%n
            newJ=(j+move* direactionList[direaction-1][1]+n*1000000)%n
            
            return (newI,newJ)
        direaction,move=command[commandIndex]
        newCloudLocation= [ cloudPush(i,j,move,direaction)   for i,j in cloudLocation]
        return newCloudLocation
    for i in range(m):
        cloudLocation=cloudMover(i)

        for index,jndex in cloudLocation:
            land[index][jndex]+=1
        
        temp=copy.deepcopy(land)
        for index,jndex in cloudLocation:
            water=0
            for i in [2,4,6,8]:
                newI=index+direactionList[i-1][0]
                newJ=jndex+direactionList[i-1][1]
                if 0<=newI<n and 0<=newJ<n and temp[newI][newJ]>0:
                    water+=1
            land[index][jndex]+=water
        newCloud=[]
        for i in range(n):
            for j in range(n):
                if land[i][j]>=2 and (i,j) not in cloudLocation:
                    land[i][j]-=2
                    newCloud.append((i,j))
        cloudLocation=newCloud
    print(sum( (sum(i) for i in land) ))