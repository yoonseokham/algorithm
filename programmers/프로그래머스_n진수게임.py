def dicimalToN(base10:int ,n:int)->str:
    num='0123456789ABCDEF'
    answer=''
    if base10==0:
        return '0' 
    while(base10!=0):
        answer+=num[base10%n]
        base10//=n
    return answer[::-1]
def solution(n, t, m, p):
    answer = ''
    turn=-1
    integer=0
    while len(answer)<t:
        temp=dicimalToN(integer,n)
        for i in temp:
            turn+=1
            if turn%m==p-1:
                answer+=i
                if len(answer)==t:
                    return answer
        integer+=1
    return answer
