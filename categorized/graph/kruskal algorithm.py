# https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
# algorithm: kruskal's algorithm, graph
# date: 09.12.2020

from collections import defaultdict


class Subset:
    def __init__(self, parent, rank):
        self.parent = parent
        self.rank = rank


    def changeParent(self, parent):
        self.parent = parent
    

    def changeRank(self, rank):
        self.rank = rank


    def incrementRank(self):
        self.rank += 1


def kruskal(group, edges):
    weightSum = 0
    edges = sorted(edges, key=lambda x:x[0])
    for edge in edges:
        root = find(group, edges[0][1])
        weight, src, dst = edge[:]
        srcParent = find(group, src)
        dstParent = find(group, dst)
        if srcParent != dstParent:
            weightSum += weight
            union(group, srcParent, dstParent)
    return weightSum



def union(subsets, left, right):
    
    if subsets[left].rank > subsets[right].rank:
        subsets[right].changeParent(left)
    elif subsets[right].rank > subsets[left].rank:
        subsets[left].changeParent(right)
    
    else:
        subsets[right].changeParent(left)
        subsets[left].incrementRank()



def find(subsets, node):
    if subsets[node].parent != node:
        subsets[node].parent = find(subsets, subsets[node].parent)
    return subsets[node].parent


if __name__ == "__main__":
    V, E = list(map(int,input().strip().split()))
    group = [Subset(V, 0) for V in range(V)]
    edges = []
    for _ in range(E):
        weight, src, dst = list(map(int,input().strip().split()))
        edges.append((weight, src, dst))
    kruskal(group, edges)