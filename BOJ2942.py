import math
a,b=map(int,input().split())
a_div={}
b_div={}
for i in range(1,int(math.sqrt(a))+1):
    if a % i == 0 :
        a_div[i]=a//i
        a_div[a//i]=i
for i in range(1,int(math.sqrt(b))+1):
    if b % i == 0 :
        b_div[i]=b//i
        b_div[b//i]=i
list_a=list(a_div.keys())
list_b=list(b_div.keys())
list_a.sort(key=lambda x :-x)
list_b.sort(key=lambda x :-x)
for i in list_a:
    for j in list_b:
        if a//i==b//j:
            print(f"{a//i} {i} {j}")
