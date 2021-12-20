import sys
import itertools
import collections

if __name__ == '__main__':
    n,k = map(int,sys.stdin.readline().split())
    alphabet = [chr(ord('a')+i) for i in range(26) if not chr(ord('a')+i) in 'antica' ]
    words = []
    count = 0
    for i in range(n):
        words.append(set(sys.stdin.readline().strip())-set('antica'))
    if k < 5:
        print(0)
    elif k == 5:
        for word in words:
            if not word:
                count+=1
        print(count)
    else:
        selected_elements = list(itertools.combinations(alphabet,k-5))
        for selected_element in selected_elements:
            set_element = set(selected_element)
            local_count = 0
            for word in words:
                for ch in word:
                    if not ch in set_element:
                        break
                else:
                    local_count+=1
            count = max(count,local_count)
        print(count)

