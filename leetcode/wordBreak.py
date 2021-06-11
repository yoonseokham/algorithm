from collections import deque
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        def BFS()->bool:
            q=deque([s])
            visit=set()
            visit.add(s)
            while q:
                cur=q.popleft()
                if cur=="": return True
                for i in wordDict:
                    if cur.endswith(i) and cur[:-len(i)] not in visit:
                        q.append(cur[:-len(i)])
                        visit.add(cur[:-len(i)])
            return False
        return BFS()
