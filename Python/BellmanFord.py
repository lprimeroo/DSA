# robin-0 ( Nabil Ibtehaz)

'''
	This code implements the Bellman-Ford Algorithm
	to solve the single source shortest path problem.

'''

class Edge:

	''' 
		This is the class to model graph edges
		it has 3 attributes startingNode , 
		endingNode and weight
	'''

	# constructor
	def __init__(self,startingNode,endingNode,weight):
		self.startingNode=startingNode
		self.endingNode=endingNode
		self.weight=weight


def BellmanFord(source):

	'''
		This function implements the Bellman Ford algorithm
		to find the single source shortest path problem

		It takes the source vertex as input and returns a
		list containing the lengths of shortest paths to 
		other vertices
	'''

	shortestPaths = [ None ] * nVertices

	shortestPaths[source]=0   # path from source to source is 0 :p

	for i in range(nVertices-1):
		for j in edgeList:

			if( shortestPaths [ j.startingNode ] !=None ):

				if(shortestPaths [j.endingNode] ==None):

					shortestPaths [j.endingNode] = shortestPaths [ j.startingNode ] + j.weight

				else :
					# Relaxation
					shortestPaths [j.endingNode] = min( shortestPaths [j.endingNode] , shortestPaths [ j.startingNode ] + j.weight	)				

	# check for negative cycle

	for j in edgeList:

		if( shortestPaths [ j.startingNode ] !=None and shortestPaths [ j.endingNode ] !=None ):
				
			if ( shortestPaths [j.endingNode] > ( shortestPaths [ j.startingNode ] + j.weight ) ):

				print("Not Possible Negative Cycle Exists")

				return None

	return shortestPaths



if __name__ == "__main__":

	'''
		This is the main function.

		A simple UI is provided
	'''

	print('Vertices are 0-indexed')
	nVertices = int(input('Number of Vertices: '))

	edgeList = []

	nEdges = int(input('Number of Edges: '))
	
	for i in range(nEdges):


		print('Enter Edge ' +str(i+1) )

		startingNode = int(input('Starting Node: '))
		endingNode = int(input('Ending Node: '))
		weight = int(input('Weight: '))

		edgeList.append(Edge(startingNode,endingNode,weight))


	print("****************************************\n")
	print("Please select one of the following\n")
	choice = int(input('1. Find Shortest Path From Sources\n2. End\n'))

	while(choice==1):
		sourceNode=int(input('Source Node(0-indexed) : '))
		print(BellmanFord(sourceNode))

		print("****************************************\n")
		print("Please select one of the following\n")
		choice = int(input('1. Find Shortest Path From Sources\n2. End\n'))
