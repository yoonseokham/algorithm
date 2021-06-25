import sys
for i,j in sorted([tuple(map(int,sys.stdin.readline().rstrip().split())) for i in range(int(input()))],key=lambda x:(x[1],x[0])): print(f"{i} {j}")
