class Solution:
    matched = {'()','{}','[]'}
    def matched_pair(self,a,b):
        if a+b in self.matched:
            return True
        return False
        
    def stack_push(self,stack,input_str):
        if not stack:
            stack.append(input_str)
        else:
            if self.matched_pair(stack[-1],input_str):
                stack.pop()
            else:
                stack.append(input_str)
                
    def isValid(self, s: str) -> bool:
        stack = []
        for i in s:
            self.stack_push(stack,i)
        return True if not stack else False
            
