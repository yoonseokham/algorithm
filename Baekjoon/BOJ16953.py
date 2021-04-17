from collections import deque
import sys
queue=deque([])

a,b =map(int,input().split())
queue.append((a,0))

while queue :
    temp=queue.popleft()
    if temp[0]== b:
        print(temp[1]+1)
        sys.exit(0)
    elif temp[0] > b:
        continue
    else:
        queue.append((2*temp[0],temp[1]+1))
        queue.append((10*temp[0]+1,temp[1]+1))
print(-1)
