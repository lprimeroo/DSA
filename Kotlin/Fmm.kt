import java.util.Scanner

class Fmm {

    private fun binaryExponentiation(base: Long, power: Long, modulo: Long): Long {
        var base = base
        var power = power
        var result: Long = 1
        while (power > 0) {
            if (power and 1) {
                result = result * base % modulo
            }
            base = base * base % modulo
            power = power / 2
        }
        return result
    }

    companion object {

        fun main(args: Array<String>) {
            val base: Long
            val power: Long
            val modulo: Long
            val sc = Scanner(System.`in`)
            base = sc.nextInt()
            power = sc.nextInt()
            modulo = sc.nextInt()
            System.out.println(binaryExponentiation(base, power, modulo))
        }
    }
}