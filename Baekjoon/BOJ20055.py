from collections import deque
from types import SimpleNamespace
if __name__=="__main__":
    count=0
    n,k=map(int,input().split())
    dq=deque(SimpleNamespace(durability=i,robot=False) for i in list(map(int,input().split())))
    robot_index=[]
    def rotateBelt()-> list:
        temp=[]
        if dq[n-1].robot:
            dq[n-1].robot=False
        dq.appendleft(dq.pop())
        for i in robot_index:
            new=i+1
            if new==n-1:
                dq[new].robot=False
            else:
                temp.append(new)
        return temp

    def robotMove()->list:
        temp=[]
        for i in robot_index:
            new=i+1
            if dq[new].durability>0 and not dq[new].robot:
                dq[new].durability-=1
                dq[new].robot=True
                dq[i].robot=False
                if new==n-1:
                    dq[new].robot=False
                else:
                    temp.append(new)
            else: temp.append(i)
        return temp

    def robotPut()-> None:
        if dq[0].durability>=1:
            dq[0].robot=True
            dq[0].durability-=1
            robot_index.append(0)

    def isEnd()->bool:
        count=sum([1 for i in dq if i.durability<=0])
        return True if count>= k else False
        
    while not isEnd() :
        robot_index=rotateBelt()
        robot_index=robotMove()
        robotPut()
        count+=1
    print(count)
        