def spush(stack:list,element:str)->None:
    stack.append(element)
    while len(stack)>=4 and "".join(stack[-4:]) =="PPAP":
        for i in range(4): stack.pop()
        stack.append("P")
if __name__ == "__main__":
    stack=[]
    inputStr=input().rstrip()
    for i in inputStr:
        spush(stack,i)
    print("PPAP") if "".join(stack)=="P" else print("NP")
