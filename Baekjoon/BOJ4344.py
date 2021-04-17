import sys
n=input()
for i in range(n):
    temp=list(map(int,sys.stdin.readline().rstrip().split()[1:]))
    mean=sum(temp)/len(temp)
    cnt=0
    for j in temp:
	if(j>mean):
            cnt+=1
    print(cnt)
    print(len(temp))
    print(cnt/len(temp))
    print( round((cnt/len(temp)),3)*100,"%")
