//Problem Statement - Given number of jobs and number of applicants
//And for each applicant given that wether each applicant is
//eligible to get the job or not in the form of matrix 
#include<bits/stdc++.h>
using namespace std;

int nApplicants,nJobs; //Total number of applicant and total number of jobs

//Return 1 if a person can get the job
int dfs(vector<vector<int> > graph,int applicant ,int visited[], int result[])
{
	// cout<<"dsf"<<endl;
	for(int i=0;i<nJobs;i++)
	{
		if(graph[applicant][i]==1 && !visited[i] )
		{
			visited[i]=1;
			// int checkVal = dfs(graph,result[i],visited,result);
			if(result[i]<0 || dfs(graph,result[i],visited,result))
			{
				result[i]=applicant;
				return 1;
			}
		}
	}
	return 0;
}


//Return maximum beople that can get the job
int bipartite(vector<vector<int> > graph)
{
	int result[nJobs];
	for(int i=0;i<nJobs;i++)
	{
		result[i]=-1;
	}

	int retval =0;
	for(int applicant=0;applicant<nApplicants;applicant++)
	{

		int visited[nApplicants];
		memset(visited,0,sizeof(visited));
		if(dfs(graph,applicant,visited,result))
		{
			retval++;
		}
	}
	return retval;
}

int main()
{
	// freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

	cout<<"Enter the number of jobs : ";
	cin>>nJobs;
	cout<<"Enter the number of applicants : ";
	cin>>nApplicants;
	vector<vector<int> > graph(nApplicants);

	//Taking input if a user can have a job then its value for job is 1
	for(int i=0;i<nApplicants;i++)
	{
		cout<<"Enter the status(1/0) for applicant - "<<i+1<<" for "<<nJobs<<" Jobs!"<<endl;
		for(int j=0;j<nJobs;j++)
		{
			cout<<"For job - "<<j+1<<" : ";
			int x;
			cin>>x;
			graph[i].push_back(x);
		}
	}
	cout<<"Maximum applicants that can have job is : "<<bipartite(graph);
}