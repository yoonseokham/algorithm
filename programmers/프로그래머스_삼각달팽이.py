def solution(n):
    answer = []
    twoD=[[0 for i in range(j+1)] for  j in range(n)]
    cnt=1
    di=[1,0,-1]
    dj=[0,1,-1]
    twoD[0][0]=1
    k=0
    i=0
    j=0
    while 2*cnt < (1+n)*n:   
        try:   
            if twoD[i+di[k]][j+dj[k]]==0:
                cnt+=1
                twoD[i+di[k]][j+dj[k]]=cnt
                i=i+di[k]
                j=j+dj[k]
            else:
                k+=1
                k%=3
        except:
            k+=1
            k%=3
    for i in twoD:
        for j in i:
            answer.append(j)
    return answer
