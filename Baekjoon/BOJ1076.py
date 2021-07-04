colors=["black","brown","red","orange","yellow","green","blue","violet","grey","white"]
resistDict={color:(i,10**i) for i,color in enumerate(colors)}
values=[resistDict[input().rstrip()] for _ in range(3)]
answer=''
for value,figure in values[:-1]:
    answer+=str(value)
answer+=str(values[-1][1])[1:]
print(int(answer))
