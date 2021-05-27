class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        MaxDepth=0
        def DFS(cur,visit=set()):
            nonlocal MaxDepth
            if nums[cur] in visit:
                MaxDepth=max(len(visit),MaxDepth)
            else:
                visit.add(nums[cur])
                cur=nums[cur]
                DFS(cur,visit)
        globalVisit=set()
        for i in range(len(nums)):
            if i not in globalVisit:
                temp=set()
                DFS(i,temp)
                globalVisit=globalVisit|temp
        return MaxDepth
