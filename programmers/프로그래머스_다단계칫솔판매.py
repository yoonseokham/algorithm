from collections import defaultdict
def solution(enroll, referral, seller, amount):
    answer = []
    parent=defaultdict(lambda:[str,int])
    
    for i,j in list(zip(enroll,referral)): parent[i]=[j,0]
    
    def DFS(parent:dict,name:str,earn:int)->None:
        if name not in parent: return
        else:   
            if int(earn*0.1)!=0:
                parent[name][1]+=earn-int(earn*0.1)
                DFS(parent,parent[name][0],int(earn*0.1))
            else: parent[name][1]+=earn
    for i,v in list(zip(seller,amount)): DFS(parent,i,100*v)
    return [ j[1] for i,j in parent.items()]
