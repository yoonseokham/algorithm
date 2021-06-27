def base10_to_baseY(y):
    def converter(n):
        convert_base=y
        answer=""
        while n:
            answer+=str(n%y)
            n//=y
        return answer
    return converter
def solution(n):
    return sum([int(j)*3**i for i,j in enumerate(base10_to_baseY(3)(n)[::-1])])
