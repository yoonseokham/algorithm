from collections import defaultdict
if __name__=="__main__":
    n,youjinGrade,p=map(int,input().split())
    if n==0:
        temp=[]
    else:
        temp=list(map(int,input().split()))
    
    temp.append(youjinGrade)
    stable=[ [i,True] for i in temp]
    stable[-1][1]=False
    stable.sort(reverse=True)
    index=0
    for i,value in enumerate(stable):
        if value[1]==False:
            index=i+1
    gradeList=sorted(temp,reverse=True)
    gradeDict=defaultdict(int)
    for grade in gradeList:
        gradeDict[grade]+=1

    currentRank=0
    for grade in gradeDict.keys():
        currentRank+=1
        if grade==youjinGrade and currentRank<=p and index<=p:
            print(currentRank)
            break
        currentRank+=gradeDict[grade]-1
    else:
        print(-1)