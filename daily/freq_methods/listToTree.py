from typing import List

class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def createTree(treeList: List[int], root: TreeNode, idx: int):
    leftIdx = 2*idx + 1
    if leftIdx < len(treeList) and treeList[leftIdx] is not None:
        root.left = TreeNode(treeList[leftIdx])
        createTree(treeList, root.left, leftIdx)
    
    rightIdx = 2*idx + 2
    if rightIdx < len(treeList) and treeList[rightIdx] is not None:
        root.right = TreeNode(treeList[rightIdx])
        createTree(treeList, root.right, rightIdx)