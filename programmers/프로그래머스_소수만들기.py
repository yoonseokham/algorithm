from itertools import combinations
import math

def prime(n):
    if n <= 1:
        return False
    for i in range(2,int(math.sqrt(n))+1):
        if n%i==0:
            return False
    return True
def solution(nums):
    nums.sort()
    cnt=0
    for i in combinations(nums,3):
        if prime(i[0]+i[1]+i[2]):
            cnt+=1      
    return cnt
