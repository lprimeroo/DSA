public class SieveOfEratosthenes {

	private boolean [] sieve;

	private int numberOfPrimes;

	public SieveOfEratosthenes( int upperBound ) {
		if ( upperBound <= 1 ) {
			throw new IllegalArgumentException( "Upper bound of sieve of eratosthenes should be > 1." );
		}

		sieve = new boolean[ upperBound ];
		sieve[ 0 ] = sieve[ 1 ] = true;

		numberOfPrimes = upperBound - 2;

		for ( int i = 2; i <= Math.sqrt( sieve.length ); ++i ) {
			if ( sieve[ i ] ) continue;

			for ( int j = i * i; j < sieve.length; j += i ) {
				if ( !sieve[ j ] ) {
					sieve[ j ] = true;
					--numberOfPrimes;
				}
			}
		}
	}

	public int getNumberOfPrimes() {
		return numberOfPrimes;
	}

	public Integer[] getPrimes() {
		Integer[] primes = new Integer[ numberOfPrimes ];
		int       index  = 0;

		for ( int i = 2; i < sieve.length; i++ ) {
			if ( !sieve[ i ] ) {
				primes[ index++ ] = i;
			}
		}

		return primes;
	}

}
