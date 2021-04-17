n,total=map(int,input().split(" "))
first=0
second=0
def fibo(n):
    global first,second
    if n==1:
        first+=1
        return
    if n==2:
        second+=1
        return
    fibo(n-1)
    fibo(n-2)
fibo(n)
for i in range(1,total):
    if (total-i*first)%second==0 and (total-i*first)//second>0:
            print(i)
            print((total-i*first)//second)
            break
