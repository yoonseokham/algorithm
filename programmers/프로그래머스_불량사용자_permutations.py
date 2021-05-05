
from itertools import permutations

def matched(user_id:str,banned_id:str)->bool:
    if len(user_id)!=len(banned_id):
        return False
    else:
        for i,j in list(zip(user_id,banned_id)):
            if i!=j and j!='*':
                return False
        else:
            return True
def ListMatcher(user_list:list,banned_list:list)->bool:
    for i,j in list(zip(user_list,banned_list)):
        if not matched(i,j):
            return False
    return True
def solution(user_id, banned_id):
    answer = set()
    candidate=list(permutations(user_id,len(banned_id)))
    for i in candidate:
        if ListMatcher(i,banned_id):
            answer.add(tuple(sorted(i)))
    return len(answer)
