import sys
if __name__ == "__main__":
    n=int(input())
    weight=sorted(list(map(int,sys.stdin.readline().split())))
    temp=[0]
    for i in weight:
        if temp[-1]+1>=i:
                temp.append(temp[-1]+i)
        else:
            print(temp[-1]+1)
            break
    else:
        print(temp[-1]+1)
