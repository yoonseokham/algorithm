import sys
while True:
    a,b,c=sorted(list(map(int,sys.stdin.readline().rstrip().split())))
    if a==0 and b==0 and c==0: break
    print("right" if a*a+b*b==c*c and a!=0 and b!=0 and c!=0 else "wrong")
