# Definition for singly-linked list.
import os, sys

up = os.path.dirname(__file__)
up = os.path.dirname(up)

sys.path.append(up)

from freq_methods import sListToTree

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head: return False
        walker, runner = head, head

        while True:
            if runner.next:
                runner = runner.next
                if runner.next:
                    runner, walker = runner.next, walker.next
                else:
                    break
            else:
                break

        rHead = walker.next
        rHead = self.reverseList(rHead)

        while rHead:
            if head.val != rHead.val: return False
            head, rHead = head.next, rHead.next

        return True

    def reverseList(self, head: ListNode) -> ListNode:
        prev, curr, post = None, head, None
        while curr:
            post = curr.next
            curr.next = prev
            prev = curr
            curr = post
        return prev


if __name__ == "__main__":
    listTree = [1,2]
    Tree = sListToTree.listToTree(listTree)
    S = Solution()
    print(S.isPalindrome(Tree))
    listTree = [1,2,2,1]
    Tree = sListToTree.listToTree(listTree)
    print(S.isPalindrome(Tree))