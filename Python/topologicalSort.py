import queue

n, m = map(int, input().split())

deg = [0]*(n+1)
g = [[] for i in range(n+1)]

for i in range(m):
	u, v = map(int, input().split())
	g[u].append(v)
	deg[v] += 1

q = queue.Queue()
for i in range(1, n+1):
	if deg[i] == 0:
		q.put(i)

topoSort = []

while not q.empty():
	nod = q.get()
	topoSort.append(nod)

	for nnod in g[nod]:
		deg[nnod] -= 1
		if deg[nnod] == 0:
			q.put(nnod)

print(topoSort)
