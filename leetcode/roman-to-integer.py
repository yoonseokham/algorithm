class Solution:
    def romanToInt(self, s: str) -> int:
        number = 0
        last_roman = 0
        roman = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        for num in reversed(s):
            current_num = roman[num]
            if last_roman <= current_num:
                number += current_num
            else:
                number -= current_num
            last_roman = current_num
        return number
