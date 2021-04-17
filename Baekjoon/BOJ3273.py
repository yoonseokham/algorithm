import sys
n=int(input())
num=set(map(int,sys.stdin.readline().rstrip().split()))
target=int(input())
cnt=0
for i in num:
    if target-i in num and i*2!=target:
        cnt+=1
print(cnt//2)
