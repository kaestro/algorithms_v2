class Solution(object):
    def shortestPathLength(self, graph):
        memo, final, q, steps = set(), (1<<len(graph) - 1), [(i, 1 << i) for i in range(len(graph))], 0
        while True:
            next_q = []
            for last_node, state in q:
                if state == final: return steps
                for v in graph[last_node]:
                    next_state = state | 1 << v
                    if (next_state, v) not in memo:
                        next_q.append((v, next_state))
                        memo.add((next_state, v))
            
            q = next_q
            steps += 1