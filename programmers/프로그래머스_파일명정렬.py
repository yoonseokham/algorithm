def HeadNumberTailSpliter(file :str)->tuple:
    head=''
    num=''
    for j,i in enumerate(file):
        if i.isdigit():
            break
        head+=i.lower()
    for i in range(j,len(file)):
        if not file[i].isdigit():
            break
        num+=file[i]
    return head,int(num[:5])
def solution(files:list)->list:
    return sorted(files,key=HeadNumberTailSpliter)
