from itertools import combinations
def solution(places):
    answer = []
    def distanceDeter(place):
        person=[]
        block=set()
        def isBlocked(person1,person2):
            dist=abs(person1[0]-person2[0])+abs(person1[1]-person2[1])
            if dist==1: return False
            elif dist==2:
                if person1[0]==person2[0]:
                    if (person1[0],(person1[1]+person2[1])//2) not in block:
                        return False 
                elif person1[1]==person2[1]:
                    if ((person1[0]+person2[0])//2,person1[1]) not in block:
                        return False
                else:
                    temp=sorted([person1,person2])
                    if temp[0][0]-temp[1][0]==-1 and temp[0][1]-temp[1][1]==-1:
                        if (temp[0][0]+1,temp[0][1]) not in block or (temp[0][0],temp[0][1]+1) not in block:
                            return False
                    else:
                        if (temp[1][0]-1,temp[1][1]) not in block or (temp[1][0],temp[1][1]+1) not in block:
                            return False
            return True
        
        for i in range(5):
            for j in range(5):
                if place[i][j] == 'P':
                    person.append((i,j))
                elif place[i][j] == 'X':
                    block.add((i,j))
                    
        for person1,person2 in combinations(person,2):
            if not isBlocked(person1,person2):
                return False
        return True

    for place in places:
        if distanceDeter(place): answer.append(1)
        else: answer.append(0)
    return answer
