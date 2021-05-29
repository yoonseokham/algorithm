from itertools import combinations

def getMax(chicken,point:tuple):
    sumed=0
    for j in range(len(chicken)):
        sumed+=max( [chicken[j][i] for i in point] )

    return sumed

n,m=map(int,input().split())
chicken=[]
for i in range(n):
  temp=list(map(int,input().split()))
  chicken.append([j for j in temp])

value=0
for i in range(1,4):
  temp=list(combinations(list(range(m)),i))
  for j in temp:
      value=max(getMax(chicken,j),value)
print(value)
