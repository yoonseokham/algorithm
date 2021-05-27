import math
def CountDivideElement(num):
    divider=set()
    for i in range(1,int(math.sqrt(num))+1):
        if num%i==0: 
            divider.add(i)
            divider.add(num//i)
    return len(divider)
def solution(left, right):
    answer = 0
    for i in range(left,right+1):
        if CountDivideElement(i)%2==0: answer+=i
        else: answer-=i
    return answer
