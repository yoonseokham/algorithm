answer=[]
path=[0]
class Solution:
    def BackTracking(self,graph: List[List[int]],visit,curIndex=0):
        global path
        global answer
        if curIndex==len(graph)-1:
            answer.append(path[:])
        for i in graph[curIndex]:
            visit[i]=True
            path.append(i)
            self.BackTracking(graph,visit,i)
            del path[-1]
            visit[i]=False
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        global answer
        global path
        answer=[]
        path=[0]
        visit=[False for i in range(len(graph))]
        visit[0]=True
        self.BackTracking(graph,visit)
        return answer
