class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        matrix = [[0 for _ in range(n)] for _ in range(m)]
        answer = 0
        for i, j in indices:
            for index, _ in enumerate(matrix[i]):
                matrix[i][index] += 1
            for index in range(m):
                matrix[index][j] += 1
        for row_matrix in matrix:
            for value in row_matrix:
                if value and value % 2:
                    answer += 1
        return answer
