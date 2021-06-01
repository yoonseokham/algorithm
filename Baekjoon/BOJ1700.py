import copy
if __name__=="__main__":
    def findLatestUse(n,multiTab:set,deviceSlice:list)->int:
        using=copy.deepcopy(multiTab)
        temp=set()
        end=-1
        for i in deviceSlice:
            if i in using and len(temp)<n:
                temp.add(i)
                end=i
        if len(temp)==len(using): return end
        else: return list(using-temp)[0]

    n,k=map(int,input().split())
    device=list(map(int,input().split()))
    multiTab=set()
    popCount=0
    for i in range(len(device)):
        if device[i] in multiTab or len(multiTab)<n: multiTab.add(device[i])
        else:
            popCount+=1
            multiTab.remove(findLatestUse(n,multiTab,device[i+1:]))
            multiTab.add(device[i])
    print(popCount)
