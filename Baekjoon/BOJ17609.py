import sys
def deter(temp):
    if temp==temp[::-1]: return 0
    else:
        start=0
        end=len(temp)-1
        while start<=end:
            if temp[start]!=temp[end]:
                a=temp[:start]+temp[start+1:]
                b=temp[:end]+temp[end+1:]
                if a==a[::-1] or b==b[::-1]: return 1
                else: break
            start+=1
            end-=1
    return 2
n=int(input())
for i in range(n):
    temp=sys.stdin.readline().rstrip()
    print(deter(temp))
