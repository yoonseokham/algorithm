import collections
import sys

if __name__ == '__main__':
    MAXSIZE = 3
    inputs = []

    def oxFormater(input_string):
        result = [['.' for _ in range(MAXSIZE)] for _ in range(MAXSIZE)]
        for index, value in enumerate(input_string):
            result[index // MAXSIZE][index % MAXSIZE] = value
        return result

    def isGameOver(state):
        o_win_count = collections.defaultdict(int)
        x_win_count = collections.defaultdict(int)

        def isEnd():
            for i in range(MAXSIZE):
                for j in range(MAXSIZE):
                    if state[i][j] == '.':
                        return False
            return True

        def getDiffBetweenXAndO():
            x_count = 0
            o_count = 0
            for i in range(MAXSIZE):
                for j in range(MAXSIZE):
                    if state[i][j] == 'X':
                        x_count += 1
                    elif state[i][j] == 'O':
                        o_count += 1
            return x_count - o_count

        def both():
            o_win = False
            x_win = False
            for i, j in o_win_count.items():
                if j:
                    o_win = True
            for i, j in x_win_count.items():
                if j:
                    x_win = True
            return [x_win, o_win]

        def isBothWin():
            return all(both())

        def isDuplicateWin():
            key = ['horizantal_win', 'vertical_win']
            for win_count in (x_win_count, o_win_count):
                for i in key:
                    if win_count[i] >= 2:
                        return True
            return False

        def isOWin():
            for i, value in o_win_count.items():
                if value:
                    return True
            return False

        def isXWin():
            for i, value in x_win_count.items():
                if value:
                    return True
            return False

        for win_count, WIN in zip(
            [
                x_win_count,
                o_win_count,
            ],
            [
                ['X', 'X', 'X'],
                ['O', 'O', 'O'],
            ],
        ):
            for i in range(MAXSIZE):
                if [state[i][k] for k in range(MAXSIZE)] == WIN:
                    win_count['horizantal_win'] += 1
                if [state[k][i] for k in range(MAXSIZE)] == WIN:
                    win_count['vertical_win'] += 1

            if [state[i][i] for i in range(MAXSIZE)] == WIN:
                win_count['cross_win'] += 1
            if [state[0][2], state[1][1], state[2][0]] == WIN:
                win_count['cross_win'] += 1

        if isBothWin() or isDuplicateWin():
            return False
        if isXWin() and getDiffBetweenXAndO() == 1:
            return True
        if isOWin() and not getDiffBetweenXAndO():
            return True
        if (not isXWin() and not isOWin() and getDiffBetweenXAndO() == 1
                and isEnd()):
            return True
        return False

    while True:
        input_string = sys.stdin.readline().strip()
        if input_string == 'end':
            break
        inputs.append(oxFormater(input_string))

    for input_string in inputs:
        print('valid' if isGameOver(input_string) else 'invalid')
