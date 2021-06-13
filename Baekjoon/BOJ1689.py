import sys
#sweeping
if __name__ == "__main__":
    n=int(input())
    cordinate=[]
    cnt=0
    answer=0
    for _ in range(n):
        start,end=map(int,sys.stdin.readline().rstrip().split())
        cordinate.append((start,1))
        cordinate.append((end,-1))
    cordinate.sort()
    for i,j in cordinate:
        cnt+=j
        answer=max(cnt,answer)
    print(answer)
