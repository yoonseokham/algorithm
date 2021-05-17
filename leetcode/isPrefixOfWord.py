class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        for i,j in enumerate(sentence.split()):
            if j.startswith(searchWord):
                return i+1
        return -1
