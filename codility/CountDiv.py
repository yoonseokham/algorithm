def solution(A, B, K):
    if A==B:
        if A%K==0:
            return 1
        else:
            return 0
    head=divmod(B,K)
    bottom=divmod(A,K)
    if bottom[1]==0:
        return head[0]-bottom[0]+1
    else:
        return head[0]-bottom[0]
