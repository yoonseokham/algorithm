def solution(record):
    name=dict()
    log=[]
    for i in record:
        if i.startswith("Enter") or i.startswith("Change"):
            temp=i.split()[1:]
            name[temp[0]]=temp[1]
        log.append(i)
    Changer=lambda name,log: f"{name[log.split()[1]]}님이 들어왔습니다." if log.startswith("Enter") else f"{name[log.split()[1]]}님이 나갔습니다."
    return [Changer(name,i) for i in log if not i.startswith("Change")]
