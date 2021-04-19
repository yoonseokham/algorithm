class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        answer=dict()
        real_answer=[]
        for i in strs:
            key=tuple(sorted([j for j in i]))
            if key in answer:
                answer[key].append(i)
            else:
                answer[key]=[i]
        print(answer)
        for key,value in answer.items():
            real_answer.append(value)
        return real_answer
