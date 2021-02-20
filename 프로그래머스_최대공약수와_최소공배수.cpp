def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
    
def solution(n, m):
    answer=[]
    if n>m:
        big=n
        small=m
    else:
        big=m
        small=n
        
    answer.append(gcd(big,small))
    answer.append(big*small/gcd(big,small))
    
    return answer
