from collections import defaultdict
from itertools import product
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits=="":
            return []
        mapper=defaultdict(list)
        start=ord("a")
        adder=lambda x: 4 if x==7 or x==9 else 3
        for i in range(2,10):
            mapper[i]=[ chr(start+j) for j in range(adder(i))]
            start+=adder(i)
        temp=[mapper[int(i)] for i in list(digits)]
        return ["".join(i) for i in list(product(*temp))]
