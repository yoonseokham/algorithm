import collections


class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        group = collections.defaultdict(list)
        answer = []
        for index, groupSize in enumerate(groupSizes):
            if not group[groupSize]:
                group[groupSize].append([index])
            else:
                if len(group[groupSize][-1]) < groupSize:
                    group[groupSize][-1].append(index)
                else:
                    group[groupSize].append([index])
        for _, value in group.items():
            answer += value
        return answer
