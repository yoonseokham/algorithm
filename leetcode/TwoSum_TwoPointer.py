class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        valueAndIndex=[(j,i) for i,j in enumerate(nums)]
        valueAndIndex.sort()
        start=0
        end=len(valueAndIndex)-1
        while start<end:
            if valueAndIndex[start][0]+valueAndIndex[end][0]==target:
                return [valueAndIndex[start][1],valueAndIndex[end][1]]
            elif valueAndIndex[start][0]+valueAndIndex[end][0]<target:
                start+=1
            else:
                end-=1
            
