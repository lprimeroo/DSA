import java.util.*
import java.io.*

class EdmundKarp {
    private val MAX_V = 40 // enough for sample graph in Figure 4.24/4.25/4.26
    private val INF = 1000000000

    // we need these global variables
    private val res = arrayOfNulls<IntArray>(MAX_V) // define MAX_V appropriately
    private var mf: Int = 0
    private var f: Int = 0
    private var s: Int = 0
    private var t: Int = 0
    private val p = Vector<Integer>()

    private fun augment(v: Int, minEdge: Int) { // traverse the BFS spanning tree as in print_path (section 4.3)
        if (v == s) {
            f = minEdge
            return
        } // reach the source, record minEdge in a global variable `f'
        else if (p.get(v) !== -1) {
            augment(p.get(v), Math.min(minEdge, res[p.get(v)][v])) // recursive call
            res[p.get(v)][v] -= f
            res[v][p.get(v)] += f
        } // alter residual capacities
    }

    @Throws(Exception::class)
    fun main(args: Array<String>) {
        val V: Int
        var k: Int
        var vertex: Int
        var weight: Int

        val sc = Scanner(System.`in`)

        V = sc.nextInt()
        s = sc.nextInt()
        t = sc.nextInt()

        for (i in 0 until V) {
            res[i] = IntArray(MAX_V)
            k = sc.nextInt()
            for (j in 0 until k) {
                vertex = sc.nextInt()
                weight = sc.nextInt()
                res[i][vertex] = weight
            }
        }

        mf = 0
        while (true) { // run O(VE^2) Edmonds Karp to solve the Max Flow problem
            f = 0

            // run BFS, please examine parts of the BFS code that is different than in Section 4.3
            val q = LinkedList<Integer>()
            val dist = Vector<Integer>()
            dist.addAll(Collections.nCopies(V, INF)) // #define INF 2000000000
            q.offer(s)
            dist.set(s, 0)
            p.clear()
            p.addAll(Collections.nCopies(V, -1)) // (we have to record the BFS spanning tree)
            while (!q.isEmpty()) {                // (we need the shortest path from s to t!)
                val u = q.poll()
                if (u == t) break // immediately stop BFS if we already reach sink t
                for (v in 0 until MAX_V)
                // note: enumerating neighbors with AdjMatrix is `slow'
                    if (res[u][v] > 0 && dist.get(v) === INF) { // res[u][v] can change!
                        dist.set(v, dist.get(u) + 1)
                        q.offer(v)
                        p.set(v, u) // parent of vertex v is vertex u
                    }
            }

            augment(t, INF) // find the min edge weight `f' along this path, if any
            if (f == 0) break // if we cannot send any more flow (`f' = 0), terminate the loop
            mf += f // we can still send a flow, increase the max flow!
        }

        System.out.printf("%d\n", mf) // this is the max flow value of this flow graph
    }
}
