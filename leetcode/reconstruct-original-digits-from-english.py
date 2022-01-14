import collections
class Solution:
    def originalDigits(self, s: str) -> str:
        numbers_map = {'zero':0,
                    'one':1,
                    'two':2,
                    'three':3,
                    'four':4,
                    'five':5,
                    'six':6,
                    'seven':7,
                    'eight':8,
                    'nine':9,}
        numbers_list = [ 
                    'six',
                    'zero',
                    'eight',
                    'two',
                    'four',
                    'one',
                    'three',
                    'seven',
                    'five',
                    'nine',]
        numbers_set = [ set(number_list) for number_list in numbers_list]
        alphabet = collections.defaultdict(int)
        for i in s:
            alphabet[i] +=1
        target = set(s)
        answer = []
        for i,number_set in enumerate(numbers_set):
            while target&number_set == number_set:
                answer.append(numbers_map[numbers_list[i]])
                for j in numbers_list[i]:
                    alphabet[j] -= 1
                    if not alphabet[j]:
                        target.remove(j)
        return ''.join(map(str,sorted(answer)))
