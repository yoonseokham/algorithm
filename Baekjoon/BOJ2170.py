import sys
if __name__=="__main__":
    segement=sorted([tuple(map(int,sys.stdin.readline().rstrip().split())) for i in range(int(input()))])
    start,end=segement[0];answer=0
    for i,j in segement[1:]:
        if end>=i:end=max(end,j)
        else:answer+=end-start;start=i;end=j
    print(answer+end-start)
