from random import randint
#returns a^b%mod
def expo(a,b,mod):
	return (a**b)%mod

#As miller rabin is probabalistic so this function returns 1 if number is probably prime
def test(m,n):
	r=randint(2,n-3)  # Taking any random number
	p=expo(r,m,n)
	if(p==1 or p==n-1):
		return 1
	while(m!=n):
		p=expo(p,2,n)
		m*=2
		if (p == 1):
			return 0
		if (p == n-1):
			return 1
	return 0

def checkPrime(n,it):
	if(n==2 or n==3):
		return 1
	if(n<=4):
		return 0
	d=n-1
	while(d%2==0):
		d/=2
	for i in range(it):
		if(test(d,n)==0):
			return 0
	return 1

if __name__ == '__main__':
	n=input("Enter the number : ")
	it=input("Enter the iterations : ")
	if(checkPrime(n,it)==1):
		print('Number is prime')
	else :
		print('Number is not prime')