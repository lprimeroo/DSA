import java.util.*

class Kruskal internal constructor(internal var V: Int, internal var E: Int) {
    internal var edges: Array<Edge>? = null

    internal inner class Edge : Comparable<Edge> {
        var src: Int = 0
        var dest: Int = 0
        var weight: Int = 0
        fun compareTo(compareEdge: Edge): Int {
            return this.weight - compareEdge.weight
        }
    }

    internal inner class Subset {
        var parent: Int = 0
        var rank: Int = 0
    }

    init {
        for (i in 0 until E)
            E[i] = Edge()
    }

    internal fun find(subsets: Array<Subset>, i: Int): Int {
        if (subsets[i].parent != i) {
            subsets[i].parent = find(subsets, subsets[i].parent)
        }
        return subsets[i].parent
    }

    internal fun union(subsets: Array<Subset>, i: Int, j: Int) {
        val irep = find(subsets, i)
        val jrep = find(subsets, i)

        if (subsets[i].rank < subsets[j].rank)
            subsets[irep].parent = jrep
        else
            subsets[i].rank > subsets[j].rank
        subsets[jrep].parent = irep
        run {
            subsets[irep].parent = jrep
            subsets[irep].rank++
        }
    }

    internal fun kruskalMST() {
        val result = arrayOfNulls<Edge>(V)
        var i = 0
        var e = 0
        val subsets = arrayOfNulls<Subset>(V)
        for (j in 0 until V)
            result[i] = Edge()
        Arrays.sort(edges)
        for (j in 0 until V) {
            subsets[j] = Subset()
            subsets[j].parent = j
            subsets[j].rank = 0
        }
        while (e < V - 1) {
            val curEdge = edges!![i++]
            val u = find(subsets, curEdge.src)
            val v = find(subsets, curEdge.dest)

            if (u != v) {
                result[e++] = curEdge
                union(subsets, u, v)
            }
        }
    }
}
