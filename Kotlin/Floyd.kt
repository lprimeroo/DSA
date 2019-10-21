import java.util.*

class Floyd {

    fun shortestpath(adj: Array<IntArray>, path: Array<IntArray>): Array<IntArray> {

        val n = adj.size
        val ans = Array(n) { IntArray(n) }

        // Implement algorithm on a copy matrix so that the adjacency isn't
        // destroyed.
        copy(ans, adj)

        // Compute successively better paths through vertex k.
        for (k in 0 until n) {

            // Do so between each possible pair of points.
            for (i in 0 until n) {
                for (j in 0 until n) {


                    if (ans[i][k] + ans[k][j] < ans[i][j]) {
                        ans[i][j] = ans[i][k] + ans[k][j]
                        path[i][j] = path[k][j]
                    }
                }
            }
        }

        // Return the shortest path matrix.
        return ans
    }

    // Copies the contents of array b into array a. Assumes that both a and
    // b are 2D arrays of identical dimensions.
    fun copy(a: Array<IntArray>, b: Array<IntArray>) {

        for (i in a.indices)
            for (j in 0 until a[0].size)
                a[i][j] = b[i][j]
    }

    // Returns the smaller of a and b.
    fun min(a: Int, b: Int): Int {
        return if (a < b)
            a
        else
            b
    }

    fun main(args: Array<String>) {

        val stdin = Scanner(System.`in`)


        // Tests out algorithm with graph shown in class.
        val m = Array(5) { IntArray(5) }
        m[0][0] = 0
        m[0][1] = 3
        m[0][2] = 8
        m[0][3] = 10000
        m[0][4] = -4
        m[1][0] = 10000
        m[1][1] = 0
        m[1][2] = 10000
        m[1][3] = 1
        m[1][4] = 7
        m[2][0] = 10000
        m[2][1] = 4
        m[2][2] = 0
        m[2][3] = 10000
        m[2][4] = 10000
        m[3][0] = 2
        m[3][1] = 10000
        m[3][2] = -5
        m[3][3] = 0
        m[3][4] = 10000
        m[4][0] = 10000
        m[4][1] = 10000
        m[4][2] = 10000
        m[4][3] = 6
        m[4][4] = 0


        val shortpath: Array<IntArray>
        val path = Array(5) { IntArray(5) }

        // Initialize with the previous vertex for each edge. -1 indicates
        // no such vertex.
        for (i in 0..4)
            for (j in 0..4)
                if (m[i][j] == 10000)
                    path[i][j] = -1
                else
                    path[i][j] = i

        // This means that we don't have to go anywhere to go from i to i.
        for (i in 0..4)
            path[i][i] = i


        shortpath = shortestpath(m, path)

        // Prints out shortest distances.
        for (i in 0..4) {
            for (j in 0..4)
                System.out.print(shortpath[i][j].toString() + " ")
            System.out.println()
        }

        System.out.println("From where to where do you want to find the shortest path?(0 to 4)")
        val start = stdin.nextInt()
        var end = stdin.nextInt()

        // The path will always end at end.
        var myPath = end + ""

        // Loop through each previous vertex until you get back to start.
        while (path[start][end] != start) {
            myPath = path[start][end].toString() + " -> " + myPath
            end = path[start][end]
        }

        // Just add start to our string and print.
        myPath = start + " -> " + myPath
        System.out.println("Here's the path $myPath")

    }
}