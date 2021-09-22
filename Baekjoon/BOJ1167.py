import sys
from collections import defaultdict,namedtuple

class longest_node:
    def __init__(self,graph,n):
        self._graph=graph
        self._size=n
        self._node_info=namedtuple('node','cost node')
    def __call__(self,node):
        visit = [ True if i==node else False for i in range(self._size+1)]
        visit_list=[self._node_info(cost=0,node=node)]
        acc_cost=0
        def dfs(node):
            nonlocal visit_list,acc_cost,visit
            for num,cost in self._graph[node]:
                if not visit[num]:
                    visit[num]=True
                    acc_cost+=cost
                    visit_list.append(self._node_info(cost=acc_cost,node=num))
                    dfs(num)
                    acc_cost-=cost
        dfs(node)
        return sorted(visit_list,reverse=True)[0]
if __name__ == '__main__':
    n=int(input())
    graph=defaultdict(list)
    visit= [False for i in range(n+1)]
    for _ in range(n):
        graphInfo=list(map(int,sys.stdin.readline().split()))[:-1]
        num,childInfo=graphInfo[0],graphInfo[1:]
        for i in range(0,len(childInfo),2):
            j=i+1
            graph[num].append([childInfo[i],childInfo[j]])
    solve=longest_node(graph,n)
    node=solve(1).node
    print(solve(node).cost)
