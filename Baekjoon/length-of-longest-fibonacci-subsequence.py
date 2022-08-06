class Solution:

    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        answer = 2
        table = set(arr)
        for i in range(len(arr) - 1):
            for j in range(i + 1, len(arr)):
                pointer_first = arr[i]
                pointer_second = arr[j]
                local_answer = 2
                while pointer_first + pointer_second in table:
                    pointer_first, pointer_second = pointer_second, pointer_first + pointer_second
                    local_answer += 1
                answer = max(answer, local_answer)
        return 0 if answer == 2 else answer
