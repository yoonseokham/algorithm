target=int(input())
n=1
while True:
    if 3*n*n-3*n+2<=target:
        n+=1
    else:
        print(n)
        break
