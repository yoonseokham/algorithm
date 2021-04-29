from collections import defaultdict
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words=[i.lower() for i in re.sub("[^\w]",' ',paragraph).split() if i.lower() not in banned]
        wordCount=defaultdict(int)
        for i in words:
            wordCount[i]+=1
        return max(wordCount,key=wordCount.get)
