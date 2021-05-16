import sys
_ = input()
nums=sorted(list(map(int,sys.stdin.readline().rstrip().split())))
good=0
for i in range(len(nums)-1,-1,-1):
    targetIndex=i
    num=nums[:targetIndex]+nums[targetIndex+1:]
    start=0
    end=len(num)-1
    while start<end:
        if num[start]+num[end]<nums[targetIndex]:
            start+=1
        elif num[start]+num[end]>nums[targetIndex]:
            end-=1
        else:
            good+=1
            break
print(good)
