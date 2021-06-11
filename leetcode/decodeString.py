class Solution:
    def decodeString(self, s: str) -> str:
        originalString=""
        def closing_find(s:str,index)->int:
            stack=["["]
            for i in range(index+1,len(s)):
                if stack[-1]=="[" and s[i]== "]":
                    stack.pop()
                    if not stack: return i
                elif s[i]=="[":
                    stack.append(s[i])
        def intReturner(s,index)->int:
            for i in range(index,len(s)):
                if not s[i].isdigit(): return i
        def recursive_add(s:str,index:int,n:int):
            nonlocal originalString
            if index>=n: return
            elif s[index].isalpha():
                originalString+=s[index]
                recursive_add(s,index+1,n)
            elif s[index].isdigit():
                a=intReturner(s,index)
                for i in range(int(s[index:a])):
                    recursive_add(s,a+1,closing_find(s,a))
                recursive_add(s,closing_find(s,a)+1,n)
        recursive_add(s,0,len(s))
        return originalString
