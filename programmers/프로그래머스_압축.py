def solution(msg):
    answer=[]
    default=[i.upper() for i in 'abcdefghijklmnopqrstuvwxyz']
    temp=0
    i=0
    while i<len(msg):
        i=temp
        for j in range(i+1,len(msg)+1):
            if msg[i:j] not in default:
                answer.append(default.index(msg[i:j-1])+1)
                default.append(msg[i:j])
                temp=j-1
                break
        else:
            answer.append(default.index(msg[i:])+1)
            break
    return answer
