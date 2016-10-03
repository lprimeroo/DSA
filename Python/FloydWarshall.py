# robin-0 ( Nabil Ibtehaz)

'''
	This code implements the Floyd-Warshall Algorithm
	to solve the all pair shortest path problem.

'''

def FloydWarshall():
	global adjMatrix

	for i in range(nVertices):
		for j in range(nVertices):
			for k in range(nVertices):

				if(adjMatrix[i][k]==-1 or adjMatrix[k][j]==-1):
					continue
				
				if(adjMatrix[i][j]==-1):
					adjMatrix[i][j]=adjMatrix[i][k]+adjMatrix[k][j]
				else:
					adjMatrix[i][j]=min(adjMatrix[i][j],adjMatrix[i][k]+adjMatrix[k][j])

	return




if __name__ == "__main__":

	'''
		This is the main function.

		A simple UI is provided
	'''

	nVertices = int(input('Number of Vertices: '))

	adjMatrix=([([-1]*nVertices)]*nVertices)

	print('Input the adjacency matrix\nPut -1 if not connected\n')

	for i in range(nVertices):
		adjMatrix[i]=[int(x) for x in input('').split()]

	#print (adjMatrix)

	FloydWarshall()

	for i in range(nVertices):
		for j in range(nVertices):
			if(adjMatrix[i][j]==-1):
				adjMatrix[i][j]="Not Connected"


	print("****************************************\n")
	print("Please select one of the following\n")
	choice = int(input('1. Find Shortest Path Between Nodes\n2. End\n'))

	while(choice==1):
		u=int(input('Starting Node(0-indexed) : '))
		v=int(input('Ending Node(0-indexed) : '))
		print(adjMatrix[u][v])

		print("****************************************\n")
		print("Please select one of the following\n")
		choice = int(input('1. Find Shortest Path Between Nodes\n2. End\n'))
