class SieveOfEratosthenes(upperBound: Int) {

    private val sieve: BooleanArray

    var numberOfPrimes: Int = 0
        private set

    val primes: Array<Integer>
        get() {
            val primes = arrayOfNulls<Integer>(numberOfPrimes)
            var index = 0

            for (i in 2 until sieve.size) {
                if (!sieve[i]) {
                    primes[index++] = i
                }
            }

            return primes
        }

    init {
        if (upperBound <= 1) {
            throw IllegalArgumentException("Upper bound of sieve of eratosthenes should be > 1.")
        }

        sieve = BooleanArray(upperBound)
        sieve[1] = true
        sieve[0] = sieve[1]

        numberOfPrimes = upperBound - 2

        for (i in 2..Math.sqrt(sieve.size)) {
            if (sieve[i]) continue

            var j = i * i
            while (j < sieve.size) {
                if (!sieve[j]) {
                    sieve[j] = true
                    --numberOfPrimes
                }
                j += i
            }
        }
    }

}
