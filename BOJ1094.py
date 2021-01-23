n=int(input())

binary_num=[]
while n!=0:
    binary_num.append(n%2)
    n//=2
print(sum(binary_num))
