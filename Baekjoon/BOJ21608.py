from collections import defaultdict

def segCheck(n:int,i:int,j:int)->bool:
    return (0<=i<n and 0<=j<n)

def favorAndBlankCal(favor:defaultdict,n:int,mapper:list,num:int)->tuple:
    favorAndBlank=[]
    for i in range(len(mapper)):
        for j in range(len(mapper)):
            if mapper[i][j]!=0:
                continue
            favorCount=0
            blankCount=0
            for k in range(4):
                newI=i+int("0121"[k])-1
                newJ=j+int("1210"[k])-1
                if segCheck(n,newI,newJ):
                    if mapper[newI][newJ] in favor[num]:
                        favorCount+=1
                    if mapper[newI][newJ]==0:
                        blankCount+=1
            favorAndBlank.append((-favorCount,-blankCount,i,j))
    favorAndBlank.sort()
    return (favorAndBlank[0][2],favorAndBlank[0][3])
def satisfiedCal(mapper,favor):
    total_satisfied=0
    cal=[0,1,10,100,1000]
    for i in range(len(mapper)):
        for j in range(len(mapper)):
            satisfied=0
            for k in range(4):
                newI=i+int("0121"[k])-1
                newJ=j+int("1210"[k])-1
                if segCheck(n,newI,newJ) and  mapper[newI][newJ] in favor[mapper[i][j]] :
                    satisfied+=1
            total_satisfied+=cal[satisfied]
    return total_satisfied
if __name__ ==  "__main__":
    n=int(input())
    favor=defaultdict(list)
    mapper=[[0 for i in range(n)] for i in range(n)]
    for i in range(n*n):
        temp=list(map(int,input().split()))
        favor[temp[0]]=temp[1:]
    for i in favor.keys():
        index,jndex=favorAndBlankCal(favor,n,mapper,i)
        mapper[index][jndex]=i
    print(satisfiedCal(mapper,favor))
