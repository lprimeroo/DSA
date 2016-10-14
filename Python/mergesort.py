# ALAINA KAFKES IMPLEMENTATION - alainakafkes

## Mergesort implementation in Python
## Runtime: O(n log(n))
## Space: O(n)
## Advantages: guaranteed good complexity (no need to worry about choice of pivot as in quicksort)
## Disadvantages: more temporary data storage needed than quicksort

#def mergesort(arr):
#    if len(arr) <= 1:
#        return arr
#    midpoint = len(arr) // 2
#    return merger(mergesort(arr[:mid]), mergesort(arr[mid:]))
#def merger(arrLeft, arrRight):
#    if not arrLeft:
#        return arrRight
#    if not arrRight:
#        return arrLeft
#    if arrLeft[0] < arrRight[0]:
#        return arrLeft[0] + merger(arrLeft[1:], arrRight)
#    return arrRight[0] + merger(arrLeft, arrRight[1:])



# YASH KATARIYA IMPLEMENTATION - yashk2810
def merge(L,R,A):    # Recursive and stable(for equal numbers it preserves their original position) algorithm
	nL=len(L)
	nR=len(R)
	i=0
	j=0
	k=0

	while i<nL and j<nR:
		if L[i]<R[j]:
			A[k]=L[i]
			i+=1
		else:
			A[k]=R[j]
			j+=1
		k+=1

	while i<nL:
		A[k]=L[i]
		i+=1
		k+=1
	while j<nR:
		A[k]=R[j]
		j+=1
		k+=1


def mergesort(A):    # Time complexity is Worst Case:- O(nlogn)
	n=len(A)	     # Space complexity is O(n)
	if n<2:
		return A
	mid=n/2
	left=A[:mid]
	right=A[mid:]
	mergesort(left)
	mergesort(right)
	merge(left,right,A)
	return A

print mergesort([2,4,1,6,8,5,3])
