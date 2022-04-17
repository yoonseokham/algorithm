class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        powerOfTwo = [1 for _ in range(33)]
        for i in range(1,33):
            powerOfTwo[i] = 2*powerOfTwo[i-1]
        return n in powerOfTwo
