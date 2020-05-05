class Solution:
    def shortestPathLength(self, graph):
        N = len(graph)
        que, mem, final, steps = [(i, 1 << i) for i in range(0, N)], set(), 2 ** N - 1, 0
        while True:
            temp = []
            for node, visited in que:
                if visited == final: return steps
                for next_node in graph[node]:
                    next_mem = (next_node, visited | 1 << next_node)
                    if next_mem not in mem:
                        mem.add(next_mem)
                        temp.append(next_mem)
            steps += 1
            que = temp