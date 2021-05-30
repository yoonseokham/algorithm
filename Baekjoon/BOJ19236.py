import copy
direaction={1:[-1,0],2:[-1,-1],3:[0,-1],4:[1,-1],5:[1,0],6:[1,1],7:[0,1],8:[-1,1]}
if __name__=="__main__":
    answer_space=0
    shark_map=[[] for i in range(4)]
    for j in range(4):
        temp=list(map(int,input().split()))
        for i in range(0,8,2):
            shark_map[j].append([temp[i],temp[i+1]])
    answer=shark_map[0][0][0]
    SHARK=(100)
    BLANK=(0)
    shark_map[0][0]=[100,shark_map[0][0][1]]
    sharkInfo=[0,0,shark_map[0][0][1]]

    def iChanger(i:int):
        if i>8: return i%8
        else: return i

    def NumFishMover(shark_map,num:int,index:int,jndex:int):
        for i in range(shark_map[index][jndex][1],shark_map[index][jndex][1]+8):
            newI=index+direaction[iChanger(i)][0]
            newJ=jndex+direaction[iChanger(i)][1]
            if 0<=newI<4 and 0<=newJ<4 and shark_map[newI][newJ][0]!=SHARK:
                shark_map[index][jndex][1]=iChanger(i)
                shark_map[newI][newJ],shark_map[index][jndex]=shark_map[index][jndex],shark_map[newI][newJ]
                return

    def FishMover(shark_map):
        def Iter(k:int):
            for i in range(4):
                for j in range(4):
                    if shark_map[i][j][0]==k:
                        NumFishMover(shark_map,k,i,j)
                        return
        for k in range(1,17):
            Iter(k)

    def TotalMover(shark_map,sharkInfo,answer):
        global answer_space
        FishMover(shark_map)
        temp=copy.deepcopy(shark_map)
        move=False
        for i in range(1,4):
            newI=sharkInfo[0]+i*direaction[sharkInfo[2]][0]
            newJ=sharkInfo[1]+i*direaction[sharkInfo[2]][1]
            if  0<=newI<4 and 0<=newJ<4 and shark_map[newI][newJ][0]!=BLANK:
                move=True
                reward=shark_map[newI][newJ][0]
                shark_map[newI][newJ]=[100,shark_map[newI][newJ][1]]
                shark_map[sharkInfo[0]][sharkInfo[1]]=[BLANK,BLANK]
                TotalMover(shark_map,[newI,newJ,shark_map[newI][newJ][1]],answer+reward)
                shark_map=copy.deepcopy(temp)
        if not move:
            answer_space=max(answer_space,answer)
            return
            
    TotalMover(shark_map,sharkInfo,answer)
    print(answer_space)
