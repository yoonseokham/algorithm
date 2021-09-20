from collections import namedtuple
def solution(weights, head2head):
    answer = []
    n = len(weights)
    ranks=[]
    rank=namedtuple('rank','win heavy_win weight num')
    for i in range(n):
        win=0
        heavy_win=0
        total_game=0
        for j in range(n):
            if i==j:
                continue
            if head2head[i][j] != 'N':
                total_game+=1
                if head2head[i][j] == 'W':
                    win+=1
                    if weights[i]<weights[j]:
                        heavy_win+=1
        win_rate= win/total_game if total_game else 0
        ranks.append(rank(win_rate,heavy_win,weights[i],-(i+1)))
    return [-d for a,b,c,d in sorted(ranks,reverse=True)]
