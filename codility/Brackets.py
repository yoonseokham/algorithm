from collections import deque
def solution(S):
    A=deque([])
    if len(S)==0:
        return 1
    for i in S:
        if len(A)==0:
            A.append(i)
        else:
            if (A[len(A)-1]=='(' and i==')') or (A[len(A)-1]=='{' and i=='}') or (A[len(A)-1]=='[' and i==']'):
                A.pop()
            else:
                A.append(i)
    answer=lambda A:  1 if len(A)==0  else 0
    return answer(A)
