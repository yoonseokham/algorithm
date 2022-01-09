class Solution:
    def combinations(self,nums,size):
        answer = []
        visit = set()
        local_answer = []
        def backtrack(index = 0):
            nonlocal local_answer
            if len(local_answer) == size:
                answer.append(local_answer[:])
            else:
                for i in range(index,len(nums)):
                    if nums[i] not in visit:
                        visit.add(nums[i])
                        local_answer.append(nums[i])
                        backtrack(i+1)
                        visit.remove(nums[i])
                        local_answer.pop()
        backtrack()
        return answer
    def subsets(self, nums: List[int]) -> List[List[int]]:
        answer = []
        for i in range(len(nums)+1):
            for combination in self.combinations(nums,i):
                answer.append(combination)
        return answe
