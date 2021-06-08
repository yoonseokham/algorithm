
from collections import defaultdict,deque
def solution(begin, target, words):
    graph=defaultdict(set)
    visit=defaultdict(int)
    def differOne(a:str,b:str)->bool:
        return sum([1 if i!=j else 0  for i,j in list(zip(a,b))])==1 
    def BFS(begin,target)->int:
        q=deque([begin])
        visit[begin]=1
        while q:
            cur=q.popleft()
            for i in graph[cur]:
                if visit[i]==0:
                    visit[i]=visit[cur]+1
                    q.append(i)
        return visit[target]-1
    words.append(begin)
    for i in words:
        for j in words:
            if differOne(i,j):
                   graph[i].add(j)
                   graph[j].add(i)
    return (lambda x: 0 if x==-1 else x)(BFS(begin,target))
