def solution(expression):
    Max=0
    case= [['+','-','*'],
           ['+','*','-'],
           ['-','+','*'],
           ['-','*','+'],
           ['*','-','+'],
           ['*','+','-'],
          ]
    a=expression.replace("+"," ").replace("-"," ").replace('*',' ')
    for i in case:
        oper=[i for i in expression if i=="+" or i=='-' or i=='*']
        num=list(map(int,a.split(" ")))
        for op in i:
            j=0
            while j<len(oper):
                if op==oper[j]:
                    if oper[j]=='+':
                        num[j]=num[j]+num[j+1]
                    elif oper[j]=='-':
                        num[j]=num[j]-num[j+1]
                    elif oper[j]=='*':
                        num[j]=num[j]*num[j+1]
                    del num[j+1]
                    del oper[j]
                    j-=1
                j+=1
        Max=max(abs(num[0]),Max)
    return Max
