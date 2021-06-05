class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s_stack=[]
        t_stack=[]
        
        def spush(stack:list,element:str)->None:
            if not stack:
                if element=="#": return
                else: stack.append(element)
            elif element=="#":
                if stack[-1]!="#": stack.pop()
            else: stack.append(element)
        for i in s: spush(s_stack,i)
        for i in t: spush(t_stack,i)

        return s_stack==t_stack
