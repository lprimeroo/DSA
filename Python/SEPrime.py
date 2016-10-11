def sieve(n):
	checkArray = [1] * (n+1)
	checkArray[0] = 0
	checkArray[1] = 0

	for i in range(2,n+1):
		j = i + i
		step = j + i
		for j in range(j,n+1,i):
			checkArray[j] = 0

	for i in range(0,n+1):
		if checkArray[i] != 0:
			print(i)


if __name__ == "__main__":
	n = int(input())
	sieve(n)