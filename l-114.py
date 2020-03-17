#Flatten Binary Tree To Linked List
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        while root:
            if root.left:
                self.flatten(root.left)
                tail = root.left
                while tail.right:
                    tail = tail.right
                tail.right = root.right
                root.right = root.left
                root.left = None
            root = root.right
    
    def better_flatten(self, root: TreeNode) -> None:
        while root:
            if root.left:
                cur = root.left
                while cur.right:
                    cur = cur.right
                cur.right = root.right
                root.right = root.left
                root.left = None
            root = root.right


class problematic_Solution:
    def __init__(self):
        self.root = TreeNode(0)
        self.last = self.root

    def flatten(self, root: TreeNode) -> None:
        if root is None: return
        self.operation(root)
        root = self.root

    def operation(self, root: TreeNode) -> None:
        self.last.val = root.val
        if root.left:
            self.last.right = TreeNode(0)
            self.last = self.last.right
            self.operation(root.left)
        if root.right:
            self.last.right = TreeNode(0)
            self.last = self.last.right
            self.operation(root.right)

if __name__ == "__main__":
    one = TreeNode(1)
    two = TreeNode(2)
    three = TreeNode(3)
    four = TreeNode(4)
    five = TreeNode(5)
    six = TreeNode(6)

    one.left = two
    one.right = five
    two.left = three
    two.right = four
    five.right = six

    #ans = Solution().flatten(one)
    Solution().better_flatten(one)
    print("hello")
