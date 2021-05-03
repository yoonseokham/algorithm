testcase=int(input())
def multiDeter(numbers:set,num:str)->bool:
    for i in range(1,len(num)):
        if num[:i] in numbers:
            return True
    return False
for i in range(testcase):
    numbers=sorted([input() for i in range(int(input()))])
    numbers_set=set()
    for i in numbers:
        if not multiDeter(numbers_set,i):
            numbers_set.add(i)
        else:
            print("NO")
            break
    else:
        print("YES")
