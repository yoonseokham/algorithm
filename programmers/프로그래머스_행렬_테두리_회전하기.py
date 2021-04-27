import copy
def rotater(origin,sI,sJ,eI,eJ,rows,columns):
    answer=origin[sI][sJ]
    temped=origin[sI][sJ]
    for i in range(sJ,eJ):
        origin[sI][i+1],temped=temped,origin[sI][i+1]
        answer=min(answer,temped)
    for i in range(sI,eI):
        origin[i+1][eJ],temped=temped,origin[i+1][eJ]
        answer=min(answer,temped)
    for i in range(eJ,sJ,-1):
        origin[eI][i-1],temped=temped,origin[eI][i-1]
        answer=min(answer,temped)
    for i in range(eI,sI,-1):
        origin[i-1][sJ],temped=temped,origin[i-1][sJ]
        answer=min(answer,temped)
    return answer
def solution(rows, columns, queries):
    answer = []
    origin=[[0 for i in range(columns+1)] for i in range(rows+1)]
    num=1
    for i in range(1,rows+1):
        for j in range(1,columns+1):
            origin[i][j]=num
            num+=1
    for i in queries:
        answer.append(rotater(origin,*i,rows,columns))
    return answer
