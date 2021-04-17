def solution(s):
    answer = len(s)
    for i in range(1,len(s)//2+1):
        length=len(s)
        temp=''
        cnt=1
        for j in range(0,len(s),i):
            if temp=='':
                temp=s[j:j+i]
            elif len(s[j:j+i])==i and temp==s[j:j+i]:
                cnt+=1
            elif temp!=s[j:j+i]:
                if cnt>1:
                    length-=i*cnt-(i+len(str(cnt)))
                temp=s[j:j+i]
                cnt=1
        if cnt>1:
            length-=i*cnt-(i+len(str(cnt)))
        answer=min(answer,length)
    return answer
