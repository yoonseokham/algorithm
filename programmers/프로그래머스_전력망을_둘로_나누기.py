from collections import defaultdict
def solution(n, wires):
    answer = 1000000000
    tree=defaultdict(list)
    isConnected=set()
    for nodeA,nodeB in wires:
        tree[nodeA].append(nodeB)
        tree[nodeB].append(nodeA)
        isConnected.add((nodeA,nodeB))
        
    def cutBetweenNodeANodeB(nodeA,nodeB):
        tree[nodeA].remove(nodeB)
        tree[nodeB].remove(nodeA)
        isConnected.remove((nodeA,nodeB))
        
    def restoreConnectionNodeANodeB(nodeA,nodeB):
        tree[nodeA].append(nodeB)
        tree[nodeB].append(nodeA)
        isConnected.add((nodeA,nodeB))
        
    def TravelTree(start):
        visit = [False]*(n+1)
        def dfs(curIndex):
            visit[curIndex] = True
            for node in tree[curIndex]:
                if not visit[node]:
                    dfs(node)
        dfs(start)
        return sum(1 for i in visit if i)
    
    for nodeA,nodeB in list(isConnected):
        cutBetweenNodeANodeB(nodeA,nodeB)
        answer=min(answer,abs(TravelTree(nodeA)-TravelTree(nodeB)))
        restoreConnectionNodeANodeB(nodeA,nodeB)
    return answer
