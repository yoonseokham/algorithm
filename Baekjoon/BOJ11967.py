from collections import defaultdict,deque
if __name__ == "__main__":
    graph=defaultdict(list)
    lightUp=defaultdict(lambda:False)
    visit=defaultdict(lambda:False)
    visitAbleButNotVisit=set()
    n,m=map(int,input().split())

    def BFS():
        q=deque([(1,1)])
        visit[(1,1)]=True
        lightUp[(1,1)]=True
        while q:
            cur=q.pop()
            for i in graph[cur]:
                if not lightUp[i]: lightUp[i]=True;
            for i in list(visitAbleButNotVisit):
                if lightUp[i]:
                    visit[i]=True
                    visitAbleButNotVisit.remove(i)
                    q.append(i)
            for a in [(cur[0]+i,cur[1]+j) for i,j in [(-1,0),(0,1),(1,0),(0,-1)]]:
                if lightUp[a] and not visit[a] :
                    visit[a]=True
                    q.append(a)
                elif not lightUp[a] and not visit[a]:
                    visitAbleButNotVisit.add(a)
        return len([i for i,j in lightUp.items() if j])
    for _ in range(m):
        a,b,c,d=map(int,input().split())
        graph[(a,b)].append((c,d))
    print(BFS())
