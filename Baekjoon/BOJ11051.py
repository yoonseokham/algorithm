from functools import lru_cache
import time
import sys
sys.setrecursionlimit(10**5)
n,k=map(int,input().split())
start=time.time()
@lru_cache(maxsize=None)
def nCk(n:int,k:int)->int:
    if k==0: return 1
    if n==0: return 0
    else: return nCk(n-1,k-1)+nCk(n-1,k)
print(nCk(n,k)%10007)
