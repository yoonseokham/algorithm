def solution(N, stages):
    stages.sort()
    result=[]
    for i in range(1,N+1):
        mother=0
        sun=0
        for j in stages:
            if j>=i:
                mother+=1
            if j>i:
                sun+=1
        try:
            result.append(((mother-sun)/mother,i))
        except:
            result.append((0,i))
    result.sort(key=lambda x:(-x[0],x[1]))
    answer = [i[1] for i in result]
    return answer
