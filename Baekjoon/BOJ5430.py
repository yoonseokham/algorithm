from collections import deque
testcase=int(input())

def dequeStatus(operation,temp):
    deq=deque(temp)
    front=True
    for i in operation:
        if i == 'R':
            front = not front
        elif i == 'D' and len(deq)!=0:
            if front:
                deq.popleft()
            else:
                deq.pop()
        elif i == 'D' and len(deq)==0:
            print('error')
            return
    a=list(deq)
    if front:
        print("[",end="")
        for i in range(len(a)):
            if i == len(a)-1:
                print(f"{a[i]}",end='')
            else:
                print(f"{a[i]},",end='')
        print("]")
    else:
        a=a[::-1]
        print("[",end="")
        for i in range(len(a)):
            if i == len(a)-1:
                print(f"{a[i]}",end='')
            else:
                print(f"{a[i]},",end='')
        print("]")

for i in range(testcase):
    operation=input()
    n=int(input())
    temp=list(map(int,input().replace(',',' ').replace('[','').replace(']','').split()))
    dequeStatus(operation,temp)
