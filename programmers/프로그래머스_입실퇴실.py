def solution(enter, leave):
    n=len(enter)
    enter_index={value:i for i,value in enumerate(enter)}
    leave_index={value:i for i,value in enumerate(leave)}
    
    answer=[ set([i]) for i in range(n+1)]
    
    def answer_pusher(index,jndex,i,j):
        for k in range(index,jndex+1):
            answer[i].add(enter[k])
            answer[enter[k]].add(i)
    
    for index in range(n-1):
        for jndex in range(n-1,index,-1):
            i=enter[index]
            j=enter[jndex]
            if enter_index[i]<enter_index[j] and leave_index[i]>leave_index[j]:
                answer_pusher(index,jndex,i,j)
                break
    return [ len(i) -1 for i in answer][1:]
