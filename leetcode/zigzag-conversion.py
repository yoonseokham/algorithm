class Solution:
    def get_zigzag(self, s, numRows):
        zigzag = [[False for i in range(len(s))] for i in range(numRows)]
        counter = 0
        xais = 0
        while counter < len(s):
            for k in range(numRows - 1):
                zigzag[k][xais] = s[counter]
                counter += 1
                if counter >= len(s):
                    return zigzag
            for k in range(numRows - 1, 0, -1):
                zigzag[k][xais + numRows - 1 - k] = s[counter]
                counter += 1
                if counter >= len(s):
                    return zigzag
            xais = xais + numRows - 1
        return zigzag

    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        zigzag = self.get_zigzag(s, numRows)
        answer = ""
        for i in zigzag:
            for j in i:
                if j:
                    answer += j
        return answer
