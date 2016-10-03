# robin-0 ( Nabil Ibtehaz)

'''
	This code implements the Segment Tree data structure 
	to solve the rmq problem.

	This code provides the option of querying for both 
	the minimum or maximum element within a range

	This code also has the option of updating elements
'''


def initializeTree ( node , low , high ):
	
	'''
		This function initializes the tree
	'''

	global Tree

	if(low==high):
		Tree[node] = inputArray[low]
		return

	leftNode = node*2
	rightNode = leftNode + 1

	mid = (low+high)//2

	initializeTree(leftNode,low,mid)
	initializeTree(rightNode,mid+1,high)

	Tree[node] = Function(Tree[leftNode],Tree[rightNode])

	return

def update( node , low , high , index , value ):
	'''
		This function will change the value of an index
		and update the whole tree
	'''	

	global Tree

	if(low==high and low==index):  # this is element we need to update
		Tree[node]=value
		return 

	if(low>index or high<index):  # out of range
		return

	leftNode = node*2
	rightNode = leftNode + 1

	mid = (low+high)//2

	update(leftNode,low,mid,index,value)
	update(rightNode,mid+1,high,index,value)

	Tree[node] = Function(Tree[leftNode],Tree[rightNode])

	return

def query( node , low , high , rangeStart , rangeEnd ):
	'''
		This function does the rmq operation

		It returns the maximum or minimum value as desired
	'''

	if(rangeStart<=low and high<=rangeEnd):   # within the range
		return Tree[node]

	if(rangeEnd<low or rangeStart>high):	# out of range
		return None 

	leftNode = node*2
	rightNode = leftNode + 1

	mid = (low+high)//2

	left=query(leftNode,low,mid,rangeStart,rangeEnd)
	right=query(rightNode,mid+1,high,rangeStart,rangeEnd)

	print(low,high)
	print(left)
	print(right)

	ans = None      # initializing the ans 

	if(left!=None):
		ans=left

	if(right!=None):
		if(ans==None):
			ans=right
		else:
			ans=Function(ans,right)

	return ans 


if __name__ == "__main__":

	'''
		This is the main function.

		A simple UI is provided
	'''

	N = int(input('Number of elements: '))

	Tree=[0]*(4*N)     # safely initializing the size of the Segment Tree

	inputArray = [int(x) for x in input('Enter the input list: ').split()]
	
	choice = int(input('Enter 0 for range minimum query\nEnter 1 for range maximum query\n'))
	
	Function= max if (choice==1) else min


	initializeTree(1 , 0 , N-1)

	print("****************************************\n")
	print("Please select one of the following\n")
	choice = int(input('1. Update\n2. Query\n3. End\n'))

	while(choice!=3):
		if(choice==1):
			index=int(input('index(0-indexed) = '))
			value=int(input('value= '))

			update(1 , 0 , N-1 , index , value )

		elif(choice==2):
			rangeStart=int(input('Range Starting From (0-indexed) : '))
			rangeEnd=int(input('Range Ending at (0-indexed)  : '))

			print(query(1,0,N-1,rangeStart,rangeEnd))
		
		print("****************************************\n")
		print("Please select one of the following\n")
		choice = int(input('1. Update\n2. Query\n3. End\n'))





	
	
