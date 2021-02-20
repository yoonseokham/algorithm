def Numbers(i):
    try :
        (int(i))
        return True
    except:
        return False
def solution(dartResult):
    mark=[]
    num=""
    for i in dartResult:       
        if Numbers(i):
            num+=i
        else:
            if Numbers(num):
                mark.append(int(num))
                num=""
            if i=="D":
                mark[len(mark)-1]**=2
            elif i=="T":
                mark[len(mark)-1]**=3
            elif i=="*":
                if len(mark)>=2:
                    mark[len(mark)-1]*=2
                    mark[len(mark)-2]*=2
                else:
                    mark[len(mark)-1]*=2
            elif i=='#':
                mark[len(mark)-1]*=-1
                    
    print(mark)
    return sum(mark)
