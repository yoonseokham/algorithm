from collections import Counter
from collections import defaultdict

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        taskCounter=Counter(tasks)
        jobs=defaultdict(int)
        history=[]
        while taskCounter:
            idle=False
            temp=list(sorted(taskCounter.keys(),key=lambda x:-taskCounter[x]))
            for i in temp:
                if i not in jobs:
                    jobs[i]=n+1
                    history.append(i)
                    taskCounter[i]-=1
                    if taskCounter[i]==0:
                        del taskCounter[i]
                    break
            else:
                idle=True
                idleCount=min([jobs[i] for i in jobs.keys()])
                for i in range(idleCount):
                    history.append("idle")
                for i in list(jobs.keys()):
                    jobs[i]-=idleCount
                    if jobs[i]==0:
                        del jobs[i]
            if idle==False:
                for i in list(jobs.keys()):
                    jobs[i]-=1
                    if jobs[i]==0:
                        del jobs[i]
        return len(history)
