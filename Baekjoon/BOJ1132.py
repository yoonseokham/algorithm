from collections import defaultdict
def Counter(x:list):
    count=defaultdict(int)
    for i in x:
        for j,v in enumerate(i[::-1]):
            count[v]+=10**j
    return count
if __name__=="__main__":
    sum=0
    assign=list(range(9,0,-1))
    onlyOne=set()
    x=[]
    for i in range(int(input())):
        temp=input().rstrip()
        x.append(temp)
        onlyOne.add(temp[0])
    result=Counter(x)
    if len(result.keys())==10:
        del result[sorted([(i,j) for i,j in result.items() if not i in onlyOne],key=lambda x:x[1])[0][0]]
    for i,j in enumerate(sorted(result.items(),key=lambda x:-x[1])):
        sum+=j[1]*assign[i]
    print(sum)
