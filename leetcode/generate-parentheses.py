import itertools
class Solution:
    def isPair(self, parentheses):
        stack = []
        for i in parentheses:
            if stack and stack[-1] == '(' and i == ')':
                stack.pop()
            else:
                stack.append(i)
        return True if not stack else False
    
    def generateParenthesis(self, n: int) -> List[str]:
        parentheses = ('(',')')
        need_product = [parentheses for i in range(2*n)]
        answer = []
        for parentheses in itertools.product(*need_product):
            if self.isPair(parentheses):
                answer.append(''.join(parentheses))
        return answer
