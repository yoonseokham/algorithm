from itertools import permutations
import sys

if __name__ == '__main__':
    answer=0
    n=int(sys.stdin.readline())
    score_info=[list(map(int,sys.stdin.readline().rstrip().split())) for i in range(n)]

    def play_game()->int:
        total_score=0
        start_hiter=0
        for ining_num,ining in enumerate(score_info):
            score=0
            out_count=0
            b1=0
            b2=0
            b3=0
            index=start_hiter-1
            while True:
                index=(index+1)%9
                if ining[permutation[index]] == 0:
                    out_count+=1
                    if out_count == 3:
                        total_score+=score
                        start_hiter=(index+1)%9
                        break
                elif ining[permutation[index]] in [1,2,3,4]:
                    if ining[permutation[index]] == 1:
                        score+=b3
                        b1,b2,b3 = 1, b1, b2
                    elif ining[permutation[index]] == 2:
                        score+=b2+b3
                        b1,b2,b3 = 0 , 1, b1
                    elif ining[permutation[index]] == 3:
                        score+=b1+b2+b3
                        b1,b2,b3= 0, 0, 1
                    elif ining[permutation[index]] == 4:
                        score+=b1+b2+b3+1
                        b1,b2,b3= 0, 0, 0
        return total_score

    for permutation in map(list,permutations(range(1,9))):
        permutation.insert(3,0)
        answer=max(answer,play_game())
    print(answer)














