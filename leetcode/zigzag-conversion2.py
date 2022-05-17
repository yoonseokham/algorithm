import itertools


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        i_generator = itertools.chain(range(numRows),
                                      range(numRows - 2, 0, -1))
        infinite_i_generator = itertools.cycle(i_generator)

        zigzag_accumulate = [[] for _ in range(numRows)]

        answer = ''

        for ch, i in zip(s, infinite_i_generator):
            zigzag_accumulate[i].append(ch)

        for zigzag_column in zigzag_accumulate:
            for ch in zigzag_column:
                answer += ch

        return answer
