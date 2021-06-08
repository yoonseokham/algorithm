def solution(numbers): 
    return (lambda x :"0" if int(x)==0 else x)("".join(sorted( [ str(i) for i in numbers] ,reverse=True,key=lambda x:(str(x)*4) )))
