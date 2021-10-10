from types import SimpleNamespace
def solution(grid):
    answer = []
    numToStr=['UP','RIGHT','DOWN','LEFT']
    strToNum={'UP':0,'RIGHT':1,'DOWN':2,'LEFT':3}
    didj=list(zip([-1,0,1,0],[0,1,0,-1]))
    n=len(grid)
    m=len(grid[0])
    not_visit = [ [ [ False]*4 for j in range(m)] for i in range(n)]
    def next_light_calculate(start):
        curLightInfo=SimpleNamespace(i=start[0],j=start[1],direction=start[2])
        def location_calculate():
            for direction,(i,j) in zip(numToStr,didj):
                if curLightInfo.direction == strToNum[direction]:
                    curLightInfo.i = curLightInfo.i + i
                    curLightInfo.j = curLightInfo.j + j
            if curLightInfo.i<0: curLightInfo.i = n-1
            elif curLightInfo.j<0: curLightInfo.j = m-1
            elif curLightInfo.i>n-1: curLightInfo.i = 0
            elif curLightInfo.j>m-1: curLightInfo.j = 0
        def direction_calculate():
            if grid[curLightInfo.i][curLightInfo.j] == 'L':
                if numToStr[curLightInfo.direction] == 'UP': 
                    curLightInfo.direction = strToNum['LEFT']
                elif numToStr[curLightInfo.direction] == 'LEFT': 
                    curLightInfo.direction = strToNum['DOWN']
                elif numToStr[curLightInfo.direction] == 'DOWN':
                    curLightInfo.direction = strToNum['RIGHT']
                elif numToStr[curLightInfo.direction] == 'RIGHT':
                    curLightInfo.direction = strToNum['UP']
            elif grid[curLightInfo.i][curLightInfo.j] == 'R':
                if numToStr[curLightInfo.direction] == 'UP':
                    curLightInfo.direction = strToNum['RIGHT']
                elif numToStr[curLightInfo.direction] == 'LEFT':
                    curLightInfo.direction = strToNum['UP']
                elif numToStr[curLightInfo.direction] == 'DOWN':
                    curLightInfo.direction = strToNum['LEFT']
                elif numToStr[curLightInfo.direction] == 'RIGHT':
                    curLightInfo.direction = strToNum['DOWN']
        location_calculate()
        direction_calculate()
        return (curLightInfo.i, curLightInfo.j, curLightInfo.direction)
    def light_move(start):
        length = 0
        while not not_visit[start[0]][start[1]][start[2]]:
            not_visit[start[0]][start[1]][start[2]]=True
            start=next_light_calculate(start)
            length += 1
        answer.append(length)
    for i in range(n):
        for j in range(m):
            for k in range(4):
                if not not_visit[i][j][k]:
                    light_move((i,j,k))
    return sorted(answer)
