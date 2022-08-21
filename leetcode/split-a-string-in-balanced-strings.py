import collections


class Solution:
    def balancedStringSplit(self, s: str) -> int:
        count = collections.defaultdict(int)
        answer = 0
        for ch in s:
            count[ch] += 1
            if count['R'] == count['L']:
                count.clear()
                answer += 1
        return answer
