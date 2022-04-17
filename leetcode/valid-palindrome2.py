class Solution:
    def isPalindrome(self, s: str) -> bool:
        normalized_string = [ i.lower() for i in s if i.isalpha() or i.isnumeric()]
        return normalized_string == normalized_string[::-1]
