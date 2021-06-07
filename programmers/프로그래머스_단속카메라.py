def solution(routes):
    answer = 1
    temp=sorted(routes,key=lambda x:(x[1],x[0]))
    lastCam=temp[0][1]
    for i,j in temp[1:]:
        if lastCam<i:
            answer+=1
            lastCam=j
    return answer
