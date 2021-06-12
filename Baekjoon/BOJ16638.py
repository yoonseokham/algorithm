from itertools import combinations
def difTwo(chosen:tuple)->bool:
    for i in range(1,len(chosen)):
        if chosen[i]-chosen[i-1]==1: return False
    return True
def eraser(nums:list,operator:list,grid:tuple):
    erase=0
    for i in grid:
        i-=erase
        if operator[i]=="+":
            nums[i+1]=nums[i]+nums[i+1]
        elif operator[i]=='-':
            nums[i+1]=nums[i]-nums[i+1]
        elif operator[i]=='*':
            nums[i+1]=nums[i]*nums[i+1]
        del nums[i],operator[i]
        erase+=1
    return calculator(nums,operator)

def mulFirstCal(nums:list,operator:list):
    while "*" in operator:
        i=operator.index("*")
        nums[i+1]=nums[i]*nums[i+1]
        del nums[i],operator[i]
def calculator(nums:list,operator:list)->int:
    mulFirstCal(nums,operator)
    sum=nums[0]
    for i in range(1,len(nums)):
        if operator[i-1]=="+":
            sum+=nums[i]
        elif operator[i-1]=='-':
            sum-=nums[i]
    return sum
if __name__ == "__main__":
    n=(int(input())+1)//2
    operation=input()
    nums=[int(i) for i in operation if i.isdigit()]
    operator=[ i for i in operation if not i.isdigit()]
    answer=calculator(nums[:],operator[:])
    for i in range(1,n//2+1):
        for j in [i for i in list(combinations([i for i in range(len(nums)-1)],i)) if difTwo(i)]:
            answer=max(eraser(nums[:],operator[:],j),answer)
    print(answer)
