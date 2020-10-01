fun main(args: Array<String>) {
    var result:Int = phi(25)
    println(result)                
}

private fun gcd(a: Int, b: Int): Int {
    return if (a == 0) {
        b
    } else {
        gcd(b % a, a)
    }
}

private fun phi(n: Int): Int {
    var result = 1
    for (i in 2..(n-1)) {
        if (gcd(i, n) == 1) {
            result++
        }
    }
    return result
}
