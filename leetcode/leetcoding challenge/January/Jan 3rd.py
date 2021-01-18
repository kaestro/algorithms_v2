from typing import List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        path = []
        self.findPath(original, target, path, [False])

        node = cloned
        for direction in path:
            if direction == "left":
                node = node.left
            else:
                node = node.right
        return node
    
    def findPath(self, tree: TreeNode, target: TreeNode, path: List, found: List):
        if tree is None:
            path.pop()
            return

        if tree == target:
            found[0] = True
            return

        path.append("left")
        self.findPath(tree.left, target, path, found)

        if found == [True]:
            return
        
        path.append("right")
        self.findPath(tree.right, target, path, found)

        if found == [False]:
            path.pop()



if __name__ == "__main__":
    

