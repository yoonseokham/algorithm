if __name__ == "__main__":
    testcase=int(input())
    for _ in range(testcase):
        base,indices=map(int,input().split())
        curNum=base%10
        for x in range(1,indices):
            curNum*=base;
            curNum%=10
        print(10 if curNum==0 else curNum)
