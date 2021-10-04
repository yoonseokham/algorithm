import sys
from collections import namedtuple
if __name__ == '__main__':
    n,c=map(int,sys.stdin.readline().split())
    packageInfo=namedtuple('packageInfo','start end cost')
    packages=[]
    costOfNodes=[0]*(n+1)
    answer=0
    for _ in range(int(input())):
        start,end,cost=map(int,sys.stdin.readline().split())
        packages.append(packageInfo(start,end,cost))
    packages.sort(key= lambda x:(x[1],x[0],-x[2]))
    def packageLoader(package):
        global answer
        remain_cost=c
        for i in range(package.start,package.end):
            remain_cost=min(remain_cost,c-costOfNodes[i])
        if remain_cost>0:
            load_cost=min(package.cost,remain_cost)
            answer+=load_cost
            for i in range(package.start,package.end):
                costOfNodes[i]+=load_cost
    for package in packages:
        packageLoader(package)
    print(answer)
