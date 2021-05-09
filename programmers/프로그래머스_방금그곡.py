def minReturn(start:str,end:str)->int:
    startH,startM=map(int,start.split(":"))
    endH,endM=map(int,end.split(":"))
    return endH*60+endM-startH*60-startM+1
def playedMusicCal(info:str,playTime:int)->str:
    playedMusic=[]
    i=0
    while i<playTime:
        playedMusic.append(info[i%len(info)])
        i+=1
    return "".join(playedMusic)
def Convert(temp:str)->str:
    num=["C#","D#","F#","G#","A#"]
    for i,j in enumerate(num):
        temp=temp.replace(j,str(i))
    return temp
def solution(m, musicinfos):
    answerSpace=[]
    m=Convert(m)
    for i in musicinfos:
        temp=i.split(",")
        answerSpace.append((temp[2],playedMusicCal(Convert(temp[3]),minReturn(temp[0],temp[1]))))
    answerSpace=[i for i in answerSpace if m in i[1]]
    answerSpace.sort(key=lambda x: len(x[1]),reverse=True)
    answerSpace.append(("(None)","cc"))
    return  answerSpace[0][0]
