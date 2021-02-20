def BinaryConvert(s):
    a=int(s)
    answer=''
    while a!=0:
        if a%2==0:
            answer+='0'
        else :
            answer+='1'
        a//=2
    a=list(answer)
    a.reverse()
    return "".join(a)
def solution(s):
    cnt=0
    delZero=0
    sum=0
    while s!="1":
        delZero=len(s)
        s=s.replace("0","")
        sum+=delZero-len(s)
        s=BinaryConvert(len(s))
        cnt+=1
    return [cnt,sum]
