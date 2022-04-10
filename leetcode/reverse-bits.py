class Solution:
    def dexToBin(self,n):
        answer = ''
        while n!=0:
            answer+=str(n%2)
            n//=2
        return ''.join(reversed(answer))
            
    def reverseBits(self, n: int) -> int:
        string_n = self.dexToBin(n)
        omited_len = 32-len(string_n)
        string_n = '0'*omited_len + string_n
        answer = 0
        for i,value in enumerate(string_n):
            answer+=int(value)*2**i
        return answer
