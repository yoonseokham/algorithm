import itertools
import sys
sys.setrecursionlimit(2**16+1)

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
        answer = []
        def generate(Parenthesis = []):
            if len(Parenthesis) >= 2*n:
                answer.append(Parenthesis[:])
                return
            Parenthesis.append(')')
            generate(Parenthesis)
            Parenthesis.pop()
            Parenthesis.append('(')
            generate(Parenthesis)
            Parenthesis.pop()
            
        generate()
        return [''.join(i) for i in answer if self.isPair(i)]
