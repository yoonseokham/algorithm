result=0
def collatzGuess(num,cnt=0):
    global result
    if cnt>500:
        result=-1
        return
    elif num==1:
        result=cnt
        return
    if num%2==0:
        num=num/2
    else:
        num=num*3+1
    collatzGuess(num,cnt+1)
def solution(num):
    global result
    result=0
    collatzGuess(num)
    return result
