from itertools import product
def solution(word):
    letters=[[ 'A', 'E', 'I', 'O', 'U',' '] for _ in range(5)]
    def striper(word):
        sum=''
        for i in word:
            if i!=' ':
                sum+=i
        if sum=='':
            return 'x'
        return sum
    return {value:i for i,value in enumerate(sorted(list(set([ striper(i) for i in product(*letters) ]))))}[word]+1
