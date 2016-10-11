from math import *

def sieve(limit,prime):
	mark = []
	
	for i in range(0,limit+1):
		mark.append(True)

	mark[0] = False
	mark[1] = False

	
	p = 2
	
	while (p*p <= limit):
		if(mark[p] == True):
			i=p*2
			while(i<limit):
				mark[i]=False
				i += p
		p=p+1

	for p in range(limit):
		if(mark[p] == True):
			prime.append(p)
			

def segmented(limit):
	prime = []
	limit = int(sqrt(limit))
	sieve(limit,prime)
	low = limit
	high = 2*limit

	a = 0
	while(a < len(prime)):
		print prime[a]
		a = a + 1

	while(low < n):
		limit = limit + 1
		mark = [0] * limit

		for i in range(0,limit):
			mark[i] = True

		i = 0
		while(i < len(prime)):
			lowl = low/prime[i] * prime[i]
			if(lowl < low):
				lowl = lowl + prime[i]

			j = lowl
			while(j<high):
				mark[j-low] = False
				j = j + prime[i]
			i = i + 1

		k = low
		while(k < high):
			if(mark[k - low] == True):
				print k
			k = k + 1

		low = low + limit;
		high = high + limit;
		if(high >= n):
			high = n








	


if (__name__ == "__main__"):
	n = int(raw_input())
	print "Primes are:"
	segmented(n)

