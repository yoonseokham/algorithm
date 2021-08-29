from itertools import combinations

MAX = (10000000000000000000)
if __name__ == "__main__":
    n = int(input())
    answer=MAX
    populations = list(map(int,input().split()))
    populations.insert(0,0)
    graph = [ 0 for _ in range(n+1)]
    for i in range(1,n+1):
        temp = list(map(int,input().split()))[1:]
        graph[i]=temp
    allNodes=set(range(1,n+1))
    
    def isConnected(nodes:tuple) -> bool:
        visited = [False for _ in range(n+1)]
        def DFS(node):
            visited[node] = True
            for nextNode in graph[node]:
                if nextNode in nodes and not visited[nextNode]:
                    DFS(nextNode)
        DFS(nodes[0])
        for i in nodes:
            if not visited[i]: return False
        return True
    
    def costCalculator(nodes):
        return sum(populations[i] for i in nodes) 

    for i in range(1,n):
        for combination in combinations(range(1,n+1),i):
            nodesA = tuple(allNodes - set(combination))
            nodesB = combination
            if isConnected(nodesA) and isConnected(nodesB):
               answer=min(abs(costCalculator(nodesA)-costCalculator(nodesB)),answer)
    print(answer if answer != MAX else -1)
