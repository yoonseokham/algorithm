N=int(input())
NewNumber=N
cycle=0
while N!=NewNumber or cycle==0:
    NewNumber=(NewNumber//10+NewNumber%10)%10+NewNumber%10*10
    cycle+=1
print(cycle)
