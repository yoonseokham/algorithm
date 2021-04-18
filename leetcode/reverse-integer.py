from collections import deque
class Solution:
    def reverse(self, x: int) -> int:
        if x==0:
            return 0
        negative = (x<0)
        temp=abs(x)
        while temp%10==0 and temp!=0:
            temp//=10
        temp=str(temp)
        temp=[i for i in temp]
        answer=deque(temp[::-1])
        if negative:
            answer.appendleft('-')
        answer=int(''.join(answer))  
        if answer>2**31-1 or answer<-2**31:
            return 0
        return answer
        
