import collections
class Solution:
    def distance(self, a, b):
        if ord(a) - ord(b) >= 0:
            return ord(a) - ord(b)
        return ord(a) - ord(b) + 26
                    
    def keyMaker(self, string):
        key = []
        offset = string[0]
        for i in string[1:]:
            key.append(self.distance(offset,i))
        return tuple(key)
    
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        answer = collections.defaultdict(list)
        for string in strings:
            answer[self.keyMaker(string)].append(string)
        return [ value for key,value in answer.items()]
