import sys
def findUpperBound(docker:list,target:int)->int:
    start=0
    end=len(docker)-1
    maxIndex=-1
    while start<=end:
        mid=(start+end)//2
        if docker[mid]<=target:
            maxIndex=max(maxIndex,docker[mid])
            start=mid+1
        else:
            end=mid-1
    return maxIndex
if __name__ == "__main__":
    g=int(input())
    p=int(input())
    plane=[int(sys.stdin.readline().rstrip())-1 for i in range(p)]
    docker=[i  for i in range(g)]
    count=0
    for i in plane:
        result=findUpperBound(docker,i)
        if result==-1:
            break
        del docker[docker.index(result)]
        count+=1
    print(count)
