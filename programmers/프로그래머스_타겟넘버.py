answer=0
def recursive(numbers,target,sum=0,index=-1):
    global answer
    if index>=len(numbers)-1:
        if target==sum:
            answer+=1
    else:
        recursive(numbers,target,sum+numbers[index],index+1)
        recursive(numbers,target,sum-numbers[index],index+1)
def solution(numbers, target):
    global answer
    answer = 0
    recursive(numbers,target)
    return answer
