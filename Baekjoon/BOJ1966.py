from collections import deque
def PriorityPrinter(Docs:deque):
    def DocsBind():
        count=0
        while Docs:
            curPriority,target=Docs.popleft()
            if Docs and max(Docs)[0]>curPriority:
                Docs.append((curPriority,target))
            else:
                # print
                count+=1
                if target: return count

    return DocsBind
if __name__ == "__main__":
    testcase=int(input())
    for _ in range(testcase):
        numOfDocs,interestedDocIndex=map(int,input().split())
        Docs=deque([ (j,True) if i==interestedDocIndex else (j,False) for i,j in enumerate(map(int,input().split()))])
        solve=PriorityPrinter(Docs)
        print(solve())
