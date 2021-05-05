def matchedDeter(ban_id:str,user_id:str)->bool:
    if len(ban_id)!=len(user_id):
        return False
    else:
        for i,j in zip(list(ban_id),list(user_id)):
            if i!=j and i!="*":
                return False
    return True 
def BackTracking(index:int,user_id:list,connect:list,counter:list,result:set)->None:
    if index==len(connect):
        if index==len(set(counter)):
            result.add(tuple(sorted([user_id[i] for i in counter])))
    else:
        for i in connect[index]:
            counter.append(i)
            BackTracking(index+1,user_id,connect,counter,result)
            counter.pop()
def solution(user_id, banned_id):
    connect=[[] for i in banned_id]
    for index,i in enumerate(banned_id):
        for jndex,j in enumerate(user_id):
            if matchedDeter(i,j):
                connect[index].append(jndex)
    result=set()
    BackTracking(0,user_id,connect,[],result)
    return len(result)
