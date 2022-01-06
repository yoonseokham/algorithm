# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def list_node_to_list(self,list_node):
        iterable_list = []
        def dfs(current_node):
            if current_node:
                iterable_list.append(current_node.val)
                dfs(current_node.next)
        dfs(list_node)
        return list(reversed(iterable_list))
    
    def reversed_list_to_int(self, list_node):
        num_list_node = ''
        for num_int in list_node:
            num_list_node += str(num_int)
        return int(num_list_node)
    
    def string_to_reversed_list(self,string):
        pre_node = None
        for i in string:
            pre_node = ListNode(int(i),pre_node)
        return pre_node
    
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num1 = self.reversed_list_to_int(self.list_node_to_list(l1))
        num2 = self.reversed_list_to_int(self.list_node_to_list(l2))
        result = str(num1 + num2)
        return self.string_to_reversed_list(result)
