from collections import namedtuple
if __name__=="__main__":
    numOfCurve=int(input())
    givenCurveInfo=[]
    visitedPoint=set()
    Point=namedtuple("Point","x y")
    curveInfo=namedtuple("curveInfo","startX startY direaction generation")
    tilt90Degree=lambda x: 0 if x==3 else x+1
    direactionMap=[ Point(i,j) for i,j in zip([1,0,-1,0],[0,-1,0,1]) ]

    for _ in range(numOfCurve):
        givenCurveInfo.append(curveInfo(*tuple(map(int,input().split()))))

    def GenerateCurveAndVisitCheck(curve:curveInfo)->None:
        currentX=curve.startX
        currentY=curve.startY
        visitedPoint.add(Point(currentX,currentY))
        direactionLog=[]
        for currentGen in range(curve.generation+1):
            if direactionLog:
                for dir in reversed(direactionLog):
                    curDireation=tilt90Degree(dir)
                    direactionLog.append(curDireation)
                    currentX,currentY=currentX+direactionMap[curDireation].x,currentY+direactionMap[curDireation].y
                    visitedPoint.add(Point(currentX,currentY))
            else:
                currentX,currentY=currentX+direactionMap[curve.direaction].x,currentY+direactionMap[curve.direaction].y
                visitedPoint.add(Point(currentX,currentY))
                direactionLog.append(curve.direaction)

    def getNumOfRectangle()->int:
        count=0
        pointList=sorted([(Point.x,Point.y) for Point in visitedPoint if 0<=Point.x<=100 and 0<=Point.y<=100])
        for x,y in pointList:
            if Point(x+1,y) in visitedPoint and Point(x,y+1) in visitedPoint and Point(x+1,y+1) in visitedPoint:
                count+=1
        return count

    for info in givenCurveInfo:
        GenerateCurveAndVisitCheck(info)

    print(getNumOfRectangle())
