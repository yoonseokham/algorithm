import collections
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        visit = collections.defaultdict(bool)
        visit[tuple([ i for i in s])] = True
        answer_list =deque([[ i for i in s]])
        real_answer_list = set()
        while answer_list:
            cur = answer_list.popleft()
            real_answer_list.add(tuple(cur))
            for i in range(len(cur)):
                if i+1 < len(cur):
                    merged = "".join((cur[i],cur[i+1]))
                    if merged == ''.join(reversed(merged)):
                        result = tuple(cur[:i]+[merged]+cur[i+2:])
                        if not visit[result]:
                            visit[result] = True
                            answer_list.append(cur[:i]+[merged]+cur[i+2:])
                if i+2 < len(cur):
                    merged = "".join((cur[i],cur[i+1],cur[i+2]))
                    if merged == ''.join(reversed(merged)):
                        result = tuple(cur[:i]+[merged]+cur[i+3:])
                        if not visit[result]:
                            visit[result] = True
                            answer_list.append(cur[:i]+[merged]+cur[i+3:])
        return real_answer_list
