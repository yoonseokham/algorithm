
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        answer=[]
        path=[0]
        def BackTracking(graph: List[List[int]],visit,curIndex=0):
            if curIndex==len(graph)-1:
                answer.append(path[:])
            for i in graph[curIndex]:
                if visit[i]==True: continue
                visit[i]=True
                path.append(i)
                BackTracking(graph,visit,i)
                del path[-1]
                visit[i]=False
        visit=[False for i in range(len(graph))]
        visit[0]=True
        BackTracking(graph,visit)
        return answer
