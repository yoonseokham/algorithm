def solution(answers):
    first=[1, 2, 3, 4, 5]
    second=[2, 1, 2, 3, 2, 4, 2, 5]
    third=[3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    firstCount=0
    secondCount=0
    thirdCount=0
    for i in range(len(answers)):
        if answers[i]==first[i%len(first)]:
            firstCount+=1
        if answers[i]==second[i%len(second)]:
            secondCount+=1
        if answers[i]==third[i%len(third)]:
            thirdCount+=1
    counted=sorted([(firstCount,1),(secondCount,2),(thirdCount,3)],reverse=True)
    if counted[0][0]==counted[1][0] and counted[2][0]==counted[1][0]:
        return [1,2,3]
    elif counted[0][0]==counted[1][0]:
        return sorted([counted[0][1],counted[1][1]])
    return [counted[0][1]]
