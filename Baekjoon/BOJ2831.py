import sys
def conditionalCounter(boysOrGirlsPostive,girlsOrBoysnegative):
    count=0
    postive=boysOrGirlsPostive
    negative=girlsOrBoysnegative
    def counter():
        nonlocal count
        while postive and negative:
            if postive[-1]+negative[-1]<0:
                count+=1
                postive.pop()
                negative.pop()
            else:
                postive.pop()
        return count
    return counter
    
if __name__ == "__main__":
    input()

    boys=list(map(int,sys.stdin.readline().rstrip().split()))
    girls=list(map(int,sys.stdin.readline().rstrip().split()))

    boysPostive=sorted([i for i in boys if i>0])
    boysNegative=sorted([i for i in boys if i<0],reverse=True)
    girlsPostive=sorted([i for i in girls if i>0])
    girlsNegative=sorted([i for i in girls if i<0],reverse=True)

    bpgn=conditionalCounter(boysPostive,girlsNegative)
    gpbn=conditionalCounter(girlsPostive,boysNegative)

    print(bpgn()+gpbn())
