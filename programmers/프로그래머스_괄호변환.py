def BalncedBrackets(p:str)->bool:
    counter={'(':0,')':0}
    for i in p:
        counter[i]+=1
    return counter['(']==counter[')']
def correctBrackets(p:str)->bool:
    if BalncedBrackets(p)==False:
        return False
    stack=[]
    for i in p:
        if len(stack)==0:
            stack.append(i)
        else:
            if stack[len(stack)-1]=='(' and i==')':
                stack.pop()
            else:
                stack.append(i)
    return len(stack)==0
def pop_front_back_and_reverse(s:str)->str:
    p=['(' if i==')' else ')' for i in s[1:-1]]  
    return ''.join(p)
def recursive(p):
    if p=='':
        return ''
    else:
        u,v=p_divider(p)
        if correctBrackets(u):
            return u+recursive(v)
        else:
            return '('+recursive(v)+')'+pop_front_back_and_reverse(u)
def p_divider(p:str)->tuple:
    temp=[i for i in p]
    for i in range(1,len(p)):
        a=''.join(temp[:i])
        b=''.join(temp[i:])
        if BalncedBrackets(a) and BalncedBrackets(b):
            if p_divider(a)==(a,''):
                return (a,b)
            if p_divider(b)==(b,''):
                return (b,a)
    return (p,'')           
def solution(p):
    if correctBrackets(p):
        return p
    return recursive(p)
