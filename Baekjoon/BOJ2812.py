if __name__ == "__main__":
    _,erase=map(int,input().split())
    nums=(int(i) for i in input())
    stack=[]
    eraseCount=0
    def NumPush(inputNum):
        global eraseCount
        if stack:
            if stack[-1]<inputNum and eraseCount<erase:
                stack.pop()
                eraseCount+=1
                NumPush(inputNum)
            else:   stack.append(inputNum)
        else:   stack.append(inputNum)
    for num in nums:
        NumPush(num)
    while eraseCount<erase:
        stack.pop()
        eraseCount+=1
    print(''.join(map(str,stack)))