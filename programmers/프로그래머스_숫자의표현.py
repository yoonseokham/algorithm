def solution(n):
    start=0
    end=1
    cnt=1
    for i in range(1,n+1):
        if (start+1+end)*(end-start)==2*n:
            print(start,end=" ")
            print(end)
            cnt+=1
            start+=1
            end+=1
        elif (start+1+end)*(end-start)<2*n:
            end+=1
        elif (start+1+end)*(end-start)>2*n:
            start+=1
    return cnt
