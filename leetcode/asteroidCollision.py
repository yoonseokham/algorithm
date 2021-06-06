class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack=[]
        def spush(stack:list,element:int)->None:
            if not stack: stack.append(element)
            else:
                if stack[-1]<0: stack.append(element)
                elif stack[-1]>0:
                    if element>0: stack.append(element)
                    else:
                        if stack[-1]>abs(element): return
                        elif stack[-1]==abs(element): stack.pop()
                        else:
                            stack.pop()
                            spush(stack,element)
        for i in asteroids:
            spush(stack,i)
        return stack
