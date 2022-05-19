import collections

if __name__ == '__main__':
    pressed_count = collections.defaultdict(int)
    min_to_second = lambda min: 60 * min
    keys = [min_to_second(10), min_to_second(1), 30, 10]
    min, second = map(int, input().strip().split(':'))

    mandatory_cook_time = min_to_second(min) + second
    for key in keys:
        pressed_count[key] = mandatory_cook_time // key
        mandatory_cook_time %= key

    pressed_count_sum = sum(value for _, value in pressed_count.items())

    print(pressed_count_sum if pressed_count[30] > 0 else pressed_count_sum +
          1)
