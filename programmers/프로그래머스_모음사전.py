from itertools import product
def solution(word):
    return {value:i for i,value in enumerate(sorted([ ''.join(j) for i in range(5) for j in product('AEIOU',repeat=i+1) ]))}[word]+1
