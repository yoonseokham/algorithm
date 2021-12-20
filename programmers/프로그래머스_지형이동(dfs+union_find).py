import sys
import collections

def solution(land, height):
    sys.setrecursionlimit(100000)
    size = len(land)
    visit = [[False for _ in range(size)] for _ in range(size)]
    land_mark = [[ -1 for _ in range(size)] for _ in range(size)]
    didj = list(zip((-1,0,1,0),(0,1,0,-1)))
    graph = collections.defaultdict(set)
    graph_cost = collections.defaultdict(lambda : 100000)
    
    def dfs(index,jndex,componets):
        visit[index][jndex] = True
        componets.append((index,jndex))
        for i,j in didj:
            newI = i + index
            newJ = j + jndex
            if 0 <= newI < size and 0 <= newJ < size:
                if (not visit[newI][newJ] and 
                    abs(land[newI][newJ]-land[index][jndex]) <= height):
                    dfs(newI,newJ,componets)

    connected_land = []
    for i in range(size):
        for j in range(size):
            if not visit[i][j]:
                componets = []
                dfs(i,j,componets)
                connected_land.append(componets)
                for index,jndex in componets:
                    land_mark[index][jndex] = len(connected_land)-1
    land_info = collections.namedtuple('land_info','number ,componets')
    land_list = [land_info(i,set(value)) for i,value in enumerate(connected_land)]

    def get_next_land_cost(land_list):
        for land_iter in land_list:
            for curI,curJ in land_iter.componets:
                for i,j in didj:
                    newI = curI + i
                    newJ = curJ + j
                    if 0 <= newI < size and 0 <= newJ < size:
                        if land_mark[newI][newJ] != land_iter.number:
                            temp = graph_cost[(land_iter.number,land_mark[newI][newJ])]
                            graph_cost[(land_iter.number,land_mark[newI][newJ])] = \
                            min(abs(land[newI][newJ] - land[curI][curJ]),temp)   
                            graph[land_iter.number].add(land_mark[newI][newJ])

    get_next_land_cost(land_list)
    
    def make_mst_and_caluculate_total_weight(graph,graph_cost):
        connected_info = [i for i in range(len(land_list))]
        edges = []
        edge_info = collections.namedtuple('edge_info','start end cost')
        total = 0
        def findParent(x):
            if connected_info[x] == x:
                return x
            connected_info[x] = findParent(connected_info[x])
            return connected_info[x]
        
        def connectXY(x,y):
            x = findParent(x)
            y = findParent(y)
            if x == y:
                return False
            elif x < y:
                connected_info[y] = x
            elif x > y:
                connected_info[x] = y
            return True
                
        for start_number,componets in graph.items():
            for end_number in componets:
                edges.append(edge_info(start_number,end_number,graph_cost[(start_number,end_number)]))
        edges.sort(key = lambda x : x.cost)
        for edge in edges:
            if connectXY(edge.start,edge.end):
                total += edge.cost
        return total
    return make_mst_and_caluculate_total_weight(graph,graph_cost)
