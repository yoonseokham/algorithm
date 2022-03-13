class Solution:
    def isPair(self, bracket, stack):
        return any((stack[-1] == '(' and bracket == ')',
                    stack[-1] == '[' and bracket == ']',
                    stack[-1] == '{' and bracket == '}'))
    
    def stackPush(self, bracket, stack):
        if stack and self.isPair(bracket,stack):
            stack.pop()
        else:
            stack.append(bracket)
        
    def isValid(self, s: str) -> bool:
        stack = []
        for i in s:
            self.stackPush(i,stack)
        return not stack
