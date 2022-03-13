class Solution:
    def BinToDec(self, a:str) -> int:
        Dec = 0
        for index, value in enumerate(a[::-1]):
            value = int(value)
            Dec += value*(2**index)
        return Dec
    
    def DecToBin(self, Dec:int) -> str:
        Bin = ""
        if not Dec:
            return "0"
        while Dec > 0:
            Bin += str(Dec%2)
            Dec //= 2
        return Bin[::-1]
    
    def addBinary(self, a: str, b: str) -> str:
        result = self.BinToDec(a) + self.BinToDec(b)
        return self.DecToBin(result)
