class Graph(object):
    def __init__(self):
        self.g = {}

    def add(self, vertex1, vertex2, weight):
        if vertex1 not in self.g:
            self.g[vertex1] = {}

        if vertex2 not in self.g:
            self.g[vertex2] = {}

        self.g[vertex1][vertex2] = weight
        self.g[vertex2][vertex1] = weight

    def has_link(self, v1, v2):
        return v2 in self[v1] or v1 in self[v2]

    def edges(self):
        data = []

        for from_vertex, destinations in self.g.items():
            for to_vertex, weight in destinations.items():
                if (to_vertex, from_vertex, weight) not in data:
                    data.append((from_vertex, to_vertex, weight))

        return data

    def sorted_by_weight(self, desc=False):
        return sorted(self.edges(), key=lambda x: x[2], reverse=desc)

    def spanning_tree(self, minimum=True):
        mst = Graph()
        parent = {}
        rank = {}

        def find_parent(vertex):
            while parent[vertex] != vertex:
                vertex = parent[vertex]

            return vertex

        def union(root1, root2):
            if rank[root1] > rank[root2]:
                parent[root2] = root1
            else:
                parent[root2] = root1

                if rank[root2] == rank[root1]:
                    rank[root2] += 1

        for vertex in self.g:
            parent[vertex] = vertex
            rank[vertex] = 0

        for v1, v2, weight in self.sorted_by_weight(not minimum):
            parent1 = find_parent(v1)
            parent2 = find_parent(v2)

            if parent1 != parent2:
                mst.add(v1, v2, weight)
                union(parent1, parent2)

            if len(self) == len(mst):
                break

        return mst

    def __len__(self):
        return len(self.g.keys())

    def __getitem__(self, node):
        return self.g[node]

    def __iter__(self):
        for edge in self.edges():
            yield edge

    def __str__(self):
        return "\n".join('from %s to %s: %d' % edge for edge in self.edges())

graph = Graph()

graph.add('a', 'b', 2)
graph.add('a', 'd', 3)
graph.add('a', 'c', 3)

graph.add('b', 'a', 2)
graph.add('b', 'c', 4)
graph.add('b', 'e', 3)

graph.add('c', 'a', 3)
graph.add('c', 'b', 4)
graph.add('c', 'd', 5)
graph.add('c', 'e', 1)

graph.add('d', 'a', 3)
graph.add('d', 'c', 5)
graph.add('d', 'f', 7)

graph.add('f', 'd', 7)
graph.add('f', 'e', 8)
graph.add('f', 'g', 9)

print(graph.spanning_tree())