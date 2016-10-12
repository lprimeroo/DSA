def lcs(x,y):
	lenx=len(x)
	leny=len(y)

	# used for DP
	l=[[None]*(leny+1) for i in range(lenx+1)]

	# Following steps build L[m+1][n+1] in bottom up fashion. Note
    # that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
	for i in range(lenx+1):
		for j in range(leny+1):
			if i==0 or j==0:
				l[i][j]=0
			elif x[i-1]==y[j-1]:
				l[i][j]=1+l[i-1][j-1]
			else:
				l[i][j]=max(l[i-1][j],l[i][j-1])

	# returns the length
	print 'The length of LCS is: ',l[lenx][leny]

	# printing the longest common subsequence
	i=lenx
	j=leny
	final=''

	while i>0 and j>0:
		# If current character in X[] and Y are same, then
        # current character is part of LCS
		if x[i-1]==y[j-1]:
			final+=x[i-1]
			i-=1
			j-=1
		# If not same, then find the larger of two and
        # go in the direction of larger value
		elif l[i-1][j]>l[i][j-1]:
			i-=1
		else:
			j-=1

	print 'The LCS is: ',final[::-1]

a = raw_input()
b = raw_input()
lcs(a,b)
