if __name__=="__main__":
    data=[]
    for i in range(int(input())):
        temp=input().split()
        data.append((int(temp[0]),i,temp[1]))
    for i,_,j in sorted(data):
        print(i,j)
