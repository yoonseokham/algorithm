from collections import defaultdict,Counter
if __name__ == "__main__":
    numbers=[ int(input())  for i in range( int(input()))]
    numbers.insert(0,0)
    A=set(list(range(1,len(numbers))))
    B=set(numbers[1:])
    info=defaultdict(int)
    for value in numbers[1:]:
        info[value]+=1
    def updateAB():
        global A,B
        dif=A-B
        A-=dif
        for i in dif:
            info[numbers[i]]-=1
            if info[numbers[i]]==0:
                del info[numbers[i]]
        B=set(info)

    while A!=B:
        updateAB()
    print(len(A))
    for i in sorted(list(A)):
        print(i)
    
        
