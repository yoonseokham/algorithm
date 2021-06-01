def calDif(a,b):
    dif=0
    for i in range(len(a)):
        if a[i]!=b[i]:dif+=1
    return dif
a,b=input().split()
minVal=10000000
for i in range(0,len(b)-len(a)+1):
    minVal=min(minVal,calDif(a,b[i:i+len(a)+1]))
print(minVal)
