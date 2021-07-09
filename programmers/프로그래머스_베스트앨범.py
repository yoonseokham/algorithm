from collections import defaultdict
def solution(genres, plays):
    answer = []
    totalPlay=defaultdict(int)
    totalPlayedSong=defaultdict(list)
    for i,play in enumerate(plays):
        totalPlay[genres[i]]+=play
        totalPlayedSong[genres[i]].append((play,i))
    totalPlay=sorted([(value,key) for key,value in totalPlay.items()],reverse=True)
    for _,genres in totalPlay:
        temp=sorted(totalPlayedSong[genres],key=lambda x:(-x[0],x[1]))
        answer.extend([j for i,j in temp[:2] ]) 
    return answer
