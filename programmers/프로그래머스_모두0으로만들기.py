import collections
import heapq

def solution(a, edges):
    graph = collections.defaultdict(list)
    costs = collections.defaultdict(int)
    connected_count = collections.defaultdict(int)
    
    for i,cost in enumerate(a):
        costs[i] = cost
        
    for start, end in edges:
        graph[start].append(end)
        graph[end].append(start)
        connected_count[start] += 1
        connected_count[end] += 1

    def solve():
        info_list = [(value,key) for key,value in connected_count.items()]
        pq = []
        answer = 0
        for i in info_list:
            heapq.heappush(pq,i)
        
        while pq:
            value, key = heapq.heappop(pq)
            # find leaf node
            if value == connected_count[key] and value == 1:
                connected_count[key] = 0
                for node in graph[key]:
                    if connected_count[node] > 0:
                        connected_count[node] -= 1
                        heapq.heappush(pq,(connected_count[node],node))
                        answer += abs(costs[key])
                        costs[node] += costs[key]
                        costs[key] = 0
                        break
        for key,value in costs.items():
            if value != 0:
                return -1
        return answer
    return solve()
