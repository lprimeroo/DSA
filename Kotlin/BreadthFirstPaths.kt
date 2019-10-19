class BreadthFirstPaths {
    private var marked: BooleanArray? = null  // marked[v] = is there an s-v path
    private var edgeTo: IntArray? = null      // edgeTo[v] = previous edge on shortest s-v path
    private var distTo: IntArray? = null      // distTo[v] = number of edges shortest s-v path

    /**
     * Computes the shortest path between the source vertex `s`
     * and every other vertex in the graph `G`.
     * @param G the graph
     * @param s the source vertex
     */
    constructor(G: Graph, s: Int) {
        marked = BooleanArray(G.V())
        distTo = IntArray(G.V())
        edgeTo = IntArray(G.V())
        bfs(G, s)

        assert(check(G, s))
    }

    /**
     * Computes the shortest path between any one of the source vertices in `sources`
     * and every other vertex in graph `G`.
     * @param G the graph
     * @param sources the source vertices
     */
    constructor(G: Graph, sources: Iterable<Integer>) {
        marked = BooleanArray(G.V())
        distTo = IntArray(G.V())
        edgeTo = IntArray(G.V())
        for (v in 0 until G.V())
            distTo[v] = INFINITY
        bfs(G, sources)
    }


    // breadth-first search from a single source
    private fun bfs(G: Graph, s: Int) {
        val q = Queue<Integer>()
        for (v in 0 until G.V())
            distTo[v] = INFINITY
        distTo[s] = 0
        marked[s] = true
        q.enqueue(s)

        while (!q.isEmpty()) {
            val v = q.dequeue()
            for (w in G.adj(v)) {
                if (!marked!![w]) {
                    edgeTo[w] = v
                    distTo[w] = distTo!![v] + 1
                    marked[w] = true
                    q.enqueue(w)
                }
            }
        }
    }

    // breadth-first search from multiple sources
    private fun bfs(G: Graph, sources: Iterable<Integer>) {
        val q = Queue<Integer>()
        for (s in sources) {
            marked[s] = true
            distTo[s] = 0
            q.enqueue(s)
        }
        while (!q.isEmpty()) {
            val v = q.dequeue()
            for (w in G.adj(v)) {
                if (!marked!![w]) {
                    edgeTo[w] = v
                    distTo[w] = distTo!![v] + 1
                    marked[w] = true
                    q.enqueue(w)
                }
            }
        }
    }

    /**
     * Is there a path between the source vertex `s` (or sources) and vertex `v`?
     * @param v the vertex
     * @return `true` if there is a path, and `false` otherwise
     */
    fun hasPathTo(v: Int): Boolean {
        return marked!![v]
    }

    /**
     * Returns the number of edges in a shortest path between the source vertex `s`
     * (or sources) and vertex `v`?
     * @param v the vertex
     * @return the number of edges in a shortest path
     */
    fun distTo(v: Int): Int {
        return distTo!![v]
    }

    /**
     * Returns a shortest path between the source vertex `s` (or sources)
     * and `v`, or `null` if no such path.
     * @param v the vertex
     * @return the sequence of vertices on a shortest path, as an Iterable
     */
    fun pathTo(v: Int): Iterable<Integer>? {
        if (!hasPathTo(v)) return null
        val path = Stack<Integer>()
        var x: Int
        x = v
        while (distTo!![x] != 0) {
            path.push(x)
            x = edgeTo!![x]
        }
        path.push(x)
        return path
    }


    // check optimality conditions for single source
    private fun check(G: Graph, s: Int): Boolean {

        // check that the distance of s = 0
        if (distTo!![s] != 0) {
            StdOut.println("distance of source " + s + " to itself = " + distTo!![s])
            return false
        }

        // check that for each edge v-w dist[w] <= dist[v] + 1
        // provided v is reachable from s
        for (v in 0 until G.V()) {
            for (w in G.adj(v)) {
                if (hasPathTo(v) != hasPathTo(w)) {
                    StdOut.println("edge $v-$w")
                    StdOut.println("hasPathTo(" + v + ") = " + hasPathTo(v))
                    StdOut.println("hasPathTo(" + w + ") = " + hasPathTo(w))
                    return false
                }
                if (hasPathTo(v) && distTo!![w] > distTo!![v] + 1) {
                    StdOut.println("edge $v-$w")
                    StdOut.println("distTo[" + v + "] = " + distTo!![v])
                    StdOut.println("distTo[" + w + "] = " + distTo!![w])
                    return false
                }
            }
        }

        // check that v = edgeTo[w] satisfies distTo[w] = distTo[v] + 1
        // provided v is reachable from s
        for (w in 0 until G.V()) {
            if (!hasPathTo(w) || w == s) continue
            val v = edgeTo!![w]
            if (distTo!![w] != distTo!![v] + 1) {
                StdOut.println("shortest path edge $v-$w")
                StdOut.println("distTo[" + v + "] = " + distTo!![v])
                StdOut.println("distTo[" + w + "] = " + distTo!![w])
                return false
            }
        }

        return true
    }

    companion object {
        private val INFINITY = Integer.MAX_VALUE

        /**
         * Unit tests the `BreadthFirstPaths` data type.
         *
         * @param args the command-line arguments
         */
        fun main(args: Array<String>) {
            val `in` = In(args[0])
            val G = Graph(`in`)
            // StdOut.println(G);

            val s = Integer.parseInt(args[1])
            val bfs = BreadthFirstPaths(G, s)

            for (v in 0 until G.V()) {
                if (bfs.hasPathTo(v)) {
                    StdOut.printf("%d to %d (%d):  ", s, v, bfs.distTo(v))
                    for (x in bfs.pathTo(v)!!) {
                        if (x == s)
                            StdOut.print(x)
                        else
                            StdOut.print("-$x")
                    }
                    StdOut.println()
                } else {
                    StdOut.printf("%d to %d (-):  not connected\n", s, v)
                }

            }
        }
    }


}