from functools import lru_cache
import sys
import time
sys.setrecursionlimit(10**5)
n=int(input())
@lru_cache(maxsize=None)
def fibo(n)->int:
    if n==0: return 0
    if n==1: return 1
    else: return fibo(n-1)+fibo(n-2)
print(fibo(n))
