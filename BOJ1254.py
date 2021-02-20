def pallindrome(check):
    start=0
    end=len(check)-1
    while start<=end:
        if check[start]!=check[end]:
            return False
        start+=1
        end-=1
    return True
temp=input()
addString=[temp[i] for i in range(len(temp)-1,-1,-1)]
result=''
for i in addString:
    result+=i
answer=[]
for i in range(len(temp)+1):
    add=result[i:]
    check=temp+add
    if pallindrome(check):
        answer.append(len(check))
print(answer[len(answer)-1])
