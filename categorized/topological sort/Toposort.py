# https://practice.geeksforgeeks.org/problems/topological-sort/1


# Your task is to complete this function
# Function should return Topologically Sorted List
# Graph(adj) is a defaultict of type List
# n is no of edges
def topoSort(n, adj):
    # Code here
    stack, visited = [], [False for _ in range(n)]
    for vertex in range(n):
        if visited[vertex]:
            continue
        else:
            _topoSort(stack, visited, vertex, adj)
    return list(reversed(stack))


def _topoSort(stack, visited, vertex, adj):
    for edge in adj[vertex]:
        if not visited[edge]:
            _topoSort(stack, visited, edge, adj)
    
    visited[vertex] = True
    stack.append(vertex)



#{
#  Driver Code Starts
# Driver Program
import sys
sys.setrecursionlimit(10 ** 6)
def creategraph(e, n, arr, graph):
    i = 0
    while i < 2*e:
        graph[arr[i]].append(arr[i+1])
        i += 2


def check(graph, N, res):
    map = [0] * N
    for i in range(N):
        map[res[i]] = i
    for i in range(N):
        for v in graph[i]:
            if map[i] > map[v]:
                return False
    return True


from collections import defaultdict
def debug_main():
    t = int(input())
    for i in range(t):
        e, N = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        graph = defaultdict(list)
        creategraph(e, N, arr, graph)
        res = topoSort(N, graph)
        print(res)


def test_main():
    t = int(input())
    for i in range(t):
        e, N = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        graph = defaultdict(list)
        creategraph(e, N, arr, graph)
        res = topoSort(N, graph)

        if check(graph, N, res):
            print(1)
        else:
            print(0)






if __name__ == "__main__":
    debug_main()

# Contributed BY: Harshit Sidhwa

# } Driver Code Ends