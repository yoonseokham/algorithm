from itertools import permutations 
import math

def Prime(n):
    if n<=1:
        return False
    for i in range(2,int(math.sqrt(n))+1):
        if n%i==0:
            return False
    return True
def solution(numbers):
    answer = 0
    result=set()
    for i in range(1,len(numbers)+1):
        a=list(map(int,(map(''.join, permutations(numbers,i)))))
        for i in a:
            result.add(i)
    for i in result:
        if Prime(i):
            answer+=1
    return answer
