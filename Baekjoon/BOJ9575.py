import sys
import itertools

if __name__ == '__main__':
    testcase = int(sys.stdin.readline())
    for _ in range(testcase):
        answer = set()
        sequences = []
        sys.stdin.readline()
        sequences.append(set(map(int, sys.stdin.readline().split())))
        sys.stdin.readline()
        sequences.append(set(map(int, sys.stdin.readline().split())))
        sys.stdin.readline()
        sequences.append(set(map(int, sys.stdin.readline().split())))
        for choose_case in itertools.product(*sequences):
            if all([i in '58' for i in str(sum(choose_case))]):
                answer.add(sum(choose_case))
        print(len(answer))
