from itertools import combinations
def solution(relation):
    column=len(relation[0])
    pick=[i for i in range(column)]
    only=set()
    for i in range(1,column+1):
        for j in list(combinations(pick,i)):
            for z in only:
                if set(z)&set(j)==set(z):
                    break
            else:
                result=set()
                for k in relation:
                    result.add(tuple( k[l] for  l in j ))
                if len(result)==len(relation):
                    only.add(j)
    return len(only)
