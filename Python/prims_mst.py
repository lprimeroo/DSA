# Prim's algorithm is a greedy algorithm that
# finds a minimum spanning tree
# for a weighted undirected graph.
#
# Time complexity: O(m * n)

# Input Format:
# First line has two integers, denoting the number of nodes in the graph and
# denoting the number of edges in the graph.
# The next  lines each consist of three space separated integers,
# where  and  denote the two nodes between which the undirected edge
# exists, denotes the length of edge between the corresponding nodes.

# Output Format:
# Single integer denoting the weight of MST

import heapq
from collections import defaultdict

g = defaultdict(list)                   # graph
n, m = map(int, raw_input().split(' ')) # number of vertexes and edges
weight = 0                              # weight of MST
connected = set([])                     # set containing connected vertexes
pq = []                                 # heap

for _ in range(m):
    u, v, c = map(int, raw_input().split(' '))
    g[u].append((c, v))
    g[v].append((c, u))

start = int(raw_input())
connected.add(start)

for tup in g[start]:
    heapq.heappush(pq, tup)

while pq:
    w, b = heapq.heappop(pq)
    if b not in connected:
        weight += w
        connected.add(b)

        for tup in g[b]:
            heapq.heappush(pq, tup)

print weight
