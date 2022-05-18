import sys


def decreasing_number_generator():
    number_list = []

    def backtracking(current_string=''):
        if current_string:
            number_list.append(current_string)
        for i in "0123456789":
            if not current_string or current_string[0] < i:
                current_string = i + current_string
                backtracking(current_string)
                current_string = current_string[1:]

    backtracking()
    return sorted([int(i) for i in number_list])


if __name__ == '__main__':
    n = int(sys.stdin.readline())
    number_list = decreasing_number_generator()
    print(-1 if len(number_list) < n else number_list[n - 1])
