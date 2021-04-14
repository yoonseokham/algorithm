class Solution:
    def BS(self,temp: List[tuple],findTarget: int) -> (int,int):
        start=0
        end=len(temp)-1
        while start<=end:
            mid=(start+end)//2
            if temp[mid][0]<findTarget:
                start=mid+1
            elif temp[mid][0]>findTarget:
                end=mid-1
            else:
                return temp[mid]
        return (-1,-1)
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        answer_space=[(j,i) for i,j in enumerate(nums)]
        answer_space.sort()
        answer=[]
        for i in range(len(answer_space)):
            findTarget=target-answer_space[i][0]
            temp=answer_space[:]
            del temp[i]
            result=self.BS(temp,findTarget)
            if result!=(-1,-1):
                answer.append(answer_space[i][1])
                answer.append(result[1])
                answer.sort()
                break
        return answer
                
            
        
