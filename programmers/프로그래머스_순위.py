from collections import defaultdict
def solution(n, results):
    graph=defaultdict(list)
    answer=defaultdict(lambda:1)
    count=0
    visit=[[False for i in range(n+1)] for i in range(n+1)]

    def DFS(start,cur):
        visit[start][start]=True
        for i in graph[cur]:
            if not visit[start][i]:
                answer[i]+=1
                answer[start]+=1
                visit[start][i]=True
                DFS(start,i)
                
    for i,j in results:
        graph[i].append(j)
    for i in range(1,n+1): 
        DFS(i,i)
    for _,i in answer.items():
        if n==i: count+=1
    return count
