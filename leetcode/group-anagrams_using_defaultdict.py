from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams=defaultdict(list)
        for i in strs:
            anagrams["".join(sorted(i))].append(i)
        return list(anagrams.values())
