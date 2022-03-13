class Solution:
    def removeVowels(self, s: str) -> str:
        return ''.join(i for i in s if i not in "aeiou")
        
