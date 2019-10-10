import java.util.*

class FastDoublingFibo {
    private val hm = HashMap<Integer, Integer>()

    private fun fib(n: Int): Int {
        if (n <= 2)
            return 1

        var ans = 0
        if (hm.get(n) != null) {
            ans = hm.get(n)
            return ans
        }

        val half = n / 2
        val a = fib(half + 1)
        val b = fib(half)
        if (n % 2 == 1)
            ans = a * a + b * b
        else
            ans = 2 * a * b - b * b
        hm.put(n, ans)
        return ans
    }

    fun main(args: Array<String>) {
        val sc = Scanner(System.`in`)

        System.out.print("Enter n(0 to exit): ")
        var n = sc.nextInt()

        while (n != 0) {
            val ans = fib(n)
            System.out.println(ans)
            System.out.print("Enter n(0 to exit): ")
            n = sc.nextInt()
        }

    }
}