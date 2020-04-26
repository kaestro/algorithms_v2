from typing import List
import os, sys

up = os.path.dirname(os.path.dirname(__file__))
sys.path.append(up)

from freq_methods import sListToTree

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        notNonesCnt = len(lists)
        if notNonesCnt == 0: return None
        if lists[0] is None: return None
        root, rIdx = None, None
        for (idx, node) in enumerate(lists):
            if not node: notNonesCnt -=1
            elif root is None or node.val < root.val: root, rIdx = node, idx

        cur, lists[rIdx] = root, lists[rIdx].next
        if lists[rIdx] == None: notNonesCnt -= 1

        while notNonesCnt != 0:
            pIdx, post = None, None
            for (idx, node) in enumerate(lists):
                if not post or (node and post and node.val < post.val):
                    pIdx, post = idx, node
            cur.next = post
            cur = cur.next
            lists[pIdx] = lists[pIdx].next
            if lists[pIdx] is None:
                notNonesCnt -= 1
        
        return root


if __name__ == "__main__":
    listsInLists = [
        [1,4,5],
        [1,3,4],
        [2,6]
    ]
    listsInLists = [
        [],
        [1]
    ]
    
    listsInTree = []
    for lists in listsInLists:
        listsInTree.append(sListToTree.listToTree(lists))
    S = Solution()
    S.mergeKLists(listsInTree)