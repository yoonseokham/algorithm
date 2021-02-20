from itertools import combinations

def solution(orders, course):
    orderCount={}
    for i in orders: 
        a=list(i)
        a.sort()
        i=''.join(a)
        for j in range(2,len(i)+1): 
            for k in combinations(i,j):
                key=''
                for m in k:
                    key+=m
                if not key in orderCount.keys():
                    orderCount[key]=0
                orderCount[key]+=1
    a=list(orderCount.keys())
    answer=[]
    for i in course:
        Max=0
        Max_d=''
        for j in a:
            if i==len(j) and Max < orderCount[j] :
                Max=orderCount[j]
        if Max>1:
            for j in a:
                if i==len(j) and Max ==orderCount[j]:
                    answer.append(j)
        answer.sort()
    return answer
