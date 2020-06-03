from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        Graph = [[] for _ in range(numCourses)]
        degree = [0] * numCourses
        for post, pre in prerequisites:
            Graph[pre].append(post)
            degree[post] += 1
        
        bfs = [i for i in range(degree[i] == 0)]
        for node in bfs:
            for edge in Graph[node]:
                degree[edge] -= 1
                if degree[edge] == 0:
                    bfs.append(edge)
        return len(bfs) == numCourses
