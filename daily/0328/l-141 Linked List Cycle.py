# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head: return False

        walker, runner = head, head.next
        while not walker.next and not runner.next and not runner.next.next:
            walker = walker.next
            runner = runner.next.next
            if walker == runner: return True
        return False