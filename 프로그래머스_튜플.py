def solution(s):
    total=[]
    number=''
    for i in range(1,len(s)-1):
        if s[i]=='{':
            temp=[]
        elif s[i]=='}':
            total.append(temp)
        elif s[i]!=',':
            number+=s[i]
        elif s[i]==',':
            temp.append(int(number))
            number=''
        if i == len(s)-2:
            temp.append(int(number))
    total.sort(key= lambda x: len(x))
    answer=[]
    multi=set()
    for i in total:
        for j in i:
            if j not in multi:
                multi.add(j)
                answer.append(j)
    return answer
