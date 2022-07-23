import collections


class Solution:
    class stack:
        def __init__(self):
            self.dataForm = collections.namedtuple('data', 'value index')
            self.data = collections.deque([])
            self.whildCard = []

        def push(self, char, index):
            data = self.dataForm(char, index)
            if char == '*':
                self.whildCard.append(index)
            else:
                if not self.data:
                    self.data.append(data)
                elif char == ')' and self.data[-1].value == '(':
                    self.data.pop()
                else:
                    self.data.append(data)

        def is_valid(self):
            if not self.data:
                return True
            for index in self.whildCard:
                front = self.data[0]
                if front.value == '(' and front.index < index:
                    self.data.popleft()
                if front.value == ')' and front.index > index:
                    self.data.popleft()
                if not self.data:
                    return True
            return False

    def checkValidString(self, s: str) -> bool:
        input_data = self.stack()

        for index, char in enumerate(s):
            input_data.push(char, index)

        if input_data.is_valid():
            return True
        return False
