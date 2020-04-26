import sys
from os.path import dirname

up = dirname(dirname(dirname(__file__)))
sys.path.append(up)

from queue import Queue
from freq_methods import listToTree

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def levelOrderBottom(self, root):
        if not root: return None
        tree = [root]
        res = []
        while len(tree) > 0:
            cur_level = []
            next_level = []

            while len(tree) > 0:
                cur = tree.pop(0)
                cur_level.append(cur.val)
                if cur.left: next_level.append(cur.left)
                if cur.right: next_level.append(cur.right)

            tree = next_level
            res.insert(0, cur_level)
        
        return res
    
    def dfs_rec(self, root):
        res = []
        self.dfs_rev_helper(root, 0, res)
        return res


    def dfs_rec_helper(self, root, level, res):
        if root:
            if len(res) < level + 1:
                res.insert(0, [])
            res[-(level + 1)].append(root.val)
            self.dfs_rev_helper(root.left, level+1, res)
            self.dfs_rev_helper(root.right, level+1, res)


    def dfs_stack(self, root):
        tree = [(root, 0)]
        res = []
        while tree:
            node, level = tree.pop()
            if node:
                if len(res) < level + 1:
                    res.insert(0, [])
                res[-(level + 1)].append(node.val)
                tree.append((node.right, level + 1))
                tree.append((node.left, level + 1))
        return res


    def bfs_queue(self, root):
        tree = [(root, 0)]
        res = []
        while tree:
            node, level = tree.pop(0)
            if node:
                if len(res) < level + 1:
                    res.insert(0, [])
                res[-(level + 1)].append(node.val)
                tree.append((node.left, level + 1))
                tree.append((node.right, level + 1))
        return res




if __name__ == "__main__":
    treeInList = [3,9,20,None,None,15,7]
    tree = listToTree.listToTree(treeInList)
    S = Solution()
    print(S.levelOrderBottom(tree))
