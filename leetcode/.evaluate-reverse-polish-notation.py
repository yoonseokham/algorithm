class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operators ='+-*/'
        for token in tokens:
            if token in operators:
                top = stack.pop()
                pre_top = stack.pop()
                if token == '/':
                    result = int(int(pre_top)/int(top))
                else:
                    result = eval(token.join((pre_top,top)))
                stack.append(str(result))
            else:
                stack.append(token)
        return int(stack[0])
