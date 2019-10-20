class Dijkstra {

    // Dijkstra's algorithm to find shortest path from s to all other nodes
    fun dijkstra(G: WeightedGraph, s: Int): IntArray {
        val dist = IntArray(G.size())  // shortest known distance from "s"
        val pred = IntArray(G.size())  // preceeding node in path
        val visited = BooleanArray(G.size()) // all false initially

        for (i in dist.indices) {
            dist[i] = Integer.MAX_VALUE
        }
        dist[s] = 0

        for (i in dist.indices) {
            val next = minVertex(dist, visited)
            visited[next] = true

            // The shortest path to next is dist[next] and via pred[next].

            val n = G.neighbors(next)
            for (j in n.indices) {
                val v = n[j]
                val d = dist[next] + G.getWeight(next, v)
                if (dist[v] > d) {
                    dist[v] = d
                    pred[v] = next
                }
            }
        }
        return pred  // (ignore pred[s]==0!)
    }

    private fun minVertex(dist: IntArray, v: BooleanArray): Int {
        var x = Integer.MAX_VALUE
        var y = -1   // graph not connected, or no unvisited vertices
        for (i in dist.indices) {
            if (!v[i] && dist[i] < x) {
                y = i
                x = dist[i]
            }
        }
        return y
    }

    fun printPath(G: WeightedGraph, pred: IntArray, s: Int, e: Int) {
        val path = java.util.ArrayList()
        var x = e
        while (x != s) {
            path.add(0, G.getLabel(x))
            x = pred[x]
        }
        path.add(0, G.getLabel(s))
        System.out.println(path)
    }

}