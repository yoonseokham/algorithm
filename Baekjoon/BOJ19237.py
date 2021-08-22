import sys
from types import SimpleNamespace
from collections import defaultdict
if __name__ == "__main__":
    n, m, k = map(int, input().split())
    water = [[
        SimpleNamespace(isShark=False,
                        sharkDireaction=0,
                        sharkNum=0,
                        smellRemain=0) for _ in range(n)
    ] for _ in range(n)]
    # 제자리,상,하,좌,우
    di = [0, -1, 1, 0, 0]
    dj = [0, 0, 0, -1, 1]
    sharkLocation = [0 for _ in range(m + 1)]
    smellLocation = [list() for _ in range(m)]
    sharkPriority = [[0 for _ in range(5)] for _ in range(m + 1)]
    for i in range(n):
        temp = list(map(int, sys.stdin.readline().strip().split()))
        for j in range(n):
            if temp[j] != 0:
                water[i][j].isShark = True
                water[i][j].sharkDireaction = 0
                water[i][j].sharkNum = temp[j]
                water[i][j].smellRemain = k
                sharkLocation[temp[j]] = (i, j)
    for i, j in enumerate(list(map(int,
                                   sys.stdin.readline().strip().split()))):
        index, jndex = sharkLocation[i + 1]
        water[index][jndex].sharkDireaction = j
    for i in range(1, m + 1):
        for j in range(1, 5):
            sharkPriority[i][j] = list(map(int, input().split()))

    def smallNumSharkOnly(newLocation):
        keylist = newLocation.keys()
        for key in keylist:
            sharks = newLocation[key]
            newLocation[key] = sorted(sharks)[0]

    def smellDown():
        for i in range(n):
            for j in range(n):
                if water[i][j].isShark:
                    water[i][j].isShark = False
                    water[i][j].sharkDireaction = 0
                if water[i][j].smellRemain > 0:
                    water[i][j].smellRemain -= 1
                if water[i][j].smellRemain == 0:
                    water[i][j].sharkNum = 0

    def newSharkAssigner(newLocation):
        keylist = newLocation.keys()
        for key in keylist:
            newI, newJ = key
            newSharkNum, newSharkDireaction = newLocation[key]
            water[newI][newJ] = SimpleNamespace(
                isShark=True,
                sharkDireaction=newSharkDireaction,
                sharkNum=newSharkNum,
                smellRemain=k)

    def sharkLocationMaker():
        sharkLocation = []
        for i in range(n):
            for j in range(n):
                if water[i][j].isShark:
                    sharkLocation.append((i, j))
        return sharkLocation

    def sharkMover(sharkLocation):
        newLocation = defaultdict(list)
        for i, j in sharkLocation:
            curSharkNum = water[i][j].sharkNum
            curSharkDireaction = water[i][j].sharkDireaction
            curSharkPriority = sharkPriority[curSharkNum][curSharkDireaction]

            for k in curSharkPriority:
                newI = di[k] + i
                newJ = dj[k] + j
                if 0 <= newI < n and 0 <= newJ < n and not water[newI][
                        newJ].isShark and water[newI][newJ].smellRemain == 0:
                    newLocation[(newI, newJ)].append((curSharkNum, k))
                    break
            else:
                for k in curSharkPriority:
                    newI = di[k] + i
                    newJ = dj[k] + j
                    if 0 <= newI < n and 0 <= newJ < n and water[newI][
                            newJ].sharkNum == curSharkNum:
                        newLocation[(newI, newJ)].append((curSharkNum, k))
                        break
        smallNumSharkOnly(newLocation)
        if len(newLocation) == 1:
            return False
        smellDown()
        newSharkAssigner(newLocation)
        return True

    def answerMaker():
        cnt = 0
        while sharkMover(sharkLocationMaker()) and cnt < 1000:
            cnt += 1
        return cnt + 1

    answer = answerMaker()
    print(answer if answer <= 1000 else -1)
