import collections
import sys


class Solve:
    def __init__(self, n, info_list):
        self._answer = 0
        self._n = n
        self._info_list = info_list

    def __call__(self, day=1, acc_money=0):
        if day == n + 1:
            self._answer = max(self._answer, acc_money)
        elif day > n + 1:
            return
        else:
            self.__call__(day + 1, acc_money)
            self.__call__(day + info_list[day].day,
                          acc_money + info_list[day].price)

    def get_answer(self):
        return self._answer


if __name__ == "__main__":
    info = collections.namedtuple('info', 'day price')
    input_line = lambda: list(map(int, sys.stdin.readline().split()))
    n = input_line()[0]
    info_list = [[] if i == 0 else info(*input_line()) for i in range(n + 1)]
    solve = Solve(n, info_list)
    solve()
    print(solve.get_answer())
