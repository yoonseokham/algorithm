class Solution:
    def reverse(self, x: int) -> int:
        less_than_zero = True if x < 0 else False
        if less_than_zero:
            x *= -1
        x = int(''.join(list(reversed(str(x)))))
        if x < 2**31 :
            return -x if less_than_zero else x
        else:
            return 0
