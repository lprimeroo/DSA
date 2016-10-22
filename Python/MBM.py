# Author=====>>>Nipun Garg<<<=====

# Problem Statement - Given number of jobs and number of applicants
# And for each applicant given that wether each applicant is
# eligible to get the job or not in the form of matrix 


# Return 1 if a person can get the job
def dfs(graph, applicant, visited, result,nApplicants,nJobs):
	for i in range(0,nJobs):
		if(graph[applicant][i]==1 and (not visited[i])):
			visited[i]=1
			if( result[i]<0 or dfs(graph, result[i], visited, result, nApplicants, nJobs)):
				result[i]=applicant
				return 1
	return 0


#Return maximum people that can get the job
def bipartite(graph,nApplicants,nJobs):
	result = []
	for i in range(0,nJobs):
		result.append(-1)
	retval=0
	for i in range(nApplicants):
		visited = []
		for j in range(nApplicants):
			visited.append(0)
		if(dfs(graph, i, visited, result, nApplicants, nJobs)):
			retval+=1
	return retval


#Main function 
if __name__ == '__main__':

	# Total number of applicant and total number of jobs
	nApplicants = input("Enter the number of applicants : ")
	nJobs = input("Enter the number of jobs : ")

	graph = []

	#Taking input if a user can have a job then its value for job is 1
	for i in range(nApplicants):
		print("Enter the status(1/0) for applicant - "+str(i+1)+" for "+str(nJobs)+" Jobs!")
		temp=[]
		for j in range(nJobs):
			temp.append(input("For job - "+str(j+1)+" : "))
		graph.append(temp)

	# print(graph)
	print("Maximum applicants that can have job is : "+str(bipartite(graph, nApplicants, nJobs)))