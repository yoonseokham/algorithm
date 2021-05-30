def solution(n, times):
    MAX=(1000000000**2)
    def peopleFinCounter(time,times:list): return sum([time//i for i in times])
    def TimeFinder(n:int,times:list):
        start=0
        answer=MAX
        end=MAX
        while start<=end:
            mid=(start+end)//2
            if peopleFinCounter(mid,times)<n:
                start=mid+1
            else:
                answer=min(answer,mid)
                end=mid-1
        return answer
    return TimeFinder(n,times)
