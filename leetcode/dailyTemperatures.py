class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        temper=[(j,i) for i,j in enumerate(temperatures)]
        stack=[]
        answer=[0]*len(temperatures)
        def spush(answer,stack:list,temperature:tuple)->None:
            if not stack: stack.append(temperature)
            elif stack[-1][0]<temperature[0]:
                temp=stack.pop()
                answer[temp[1]]=temperature[1]-temp[1]
                spush(answer,stack,temperature)
            else: stack.append(temperature)
        for i in temper:
            spush(answer,stack,i)
        return answer
