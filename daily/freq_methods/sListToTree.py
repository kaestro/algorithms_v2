from typing import List

class TreeNode:

    def __init__(self, x):
        self.val = x
        self.next = None

def createTree(treeList: List[int], root: TreeNode) -> None:
    head = root
    for i in range(1, len(treeList)):
        head.next = TreeNode(treeList[i])
        head = head.next


def listToTree(treeList: List[int]) -> TreeNode:
    root = TreeNode(treeList[0])
    createTree(treeList, root)
    return root