class Knapsack0_1 {

    fun main(args: Array<String>) {
        val `val` = intArrayOf(60, 100, 120)
        val wt = intArrayOf(10, 20, 30)
        val W = 50
        val n = `val`.size

        System.out.println(knapsack(W, wt, `val`, n))
    }

    private fun knapsack(W: Int, wt: IntArray, `val`: IntArray, n: Int): Int {
        return if (W == 0 || n == 0) {
            0
        } else if (wt[n - 1] > W) {
            knapsack(W, wt, `val`, n - 1)
        } else {
            Math.max(`val`[n - 1] + knapsack(W - wt[n - 1], wt, `val`, n - 1), knapsack(W, wt, `val`, n - 1))
        }
    }

}