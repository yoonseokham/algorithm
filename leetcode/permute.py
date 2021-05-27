from itertools import permutations
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        permuted=[]
        visit=[False for i in range(len(nums))]
        def BackTracking(temp=[]):
            if len(temp)==len(nums):
                permuted.append(temp[:])
            else:
                for i in range(0,len(nums)):
                    if not visit[i]:
                        temp.append(nums[i])
                        visit[i]=True
                        BackTracking(temp)
                        del temp[-1]
                        visit[i]=False
        BackTracking()
        return permuted
