from collections import defaultdict
def solution(participant, completion):
    start=defaultdict(int)
    end=defaultdict(int)
    for i in participant:
        start[i]+=1
    for i in completion:
        end[i]+=1
    for i in end.keys():
        start[i]-=end[i]
        if start[i]==0:
            del start[i]
    return list(start.keys())[0]
