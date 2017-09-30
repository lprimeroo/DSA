#include<bits/stdc++.h>
long long int edg[500001][3],ou[100001];
int fun(const void *a,const void *b) 
{
        return *(int*)a-*(int*)b;
}
long long int findroot(long long int nfs[],long long int a)
{
	long long int t;
	if(nfs[a]<0)
	{
		return a;
	}
	else
	{
		t=findroot(nfs,nfs[a]);
		nfs[a]=t;
		return t;
	}
}
void disunion(long long int nfs[],long long int r1,long long int r2)
{
	if(fabs(nfs[r1])>fabs(nfs[r2]))
	{
		nfs[r2]=nfs[r1]+nfs[r2];
		nfs[r1]=r2;		
	}
	else
	{
		nfs[r1]=nfs[r1]+nfs[r2];
		nfs[r2]=r1;
	}	
}
int main()
{
		long long int n,m,u,v,k,w,sum=0,nfs[100001],r1,r2,total=0;
		printf("Number of vertices and edges: ");
		scanf("%lld%lld",&n,&m);
		printf("Endpoints u v & weight w for M edges\n");
		for(k=0;k<m;k++)
		{
			printf("u v w: ");
			scanf("%lld%lld%lld",&u,&v,&w);
			edg[k][0]=w;
			edg[k][1]=u;
			edg[k][2]=v;
			total+=w;
		}
	qsort(edg,m,3*sizeof(edg[0][0]),fun);
	//printf("**%lld%lld**",edg[0][2],edg[1][2]);
	//Nifty Storage Truck	
		for(k=1;k<=n;k++)
			nfs[k]=-1;
		printf("Edges in MST\n");
		for(k=0;k<m;k++)
		{
			r1=findroot(nfs,edg[k][1]);
			r2=findroot(nfs,edg[k][2]);
			if(r1==r2)
			{
				continue;
			}
			else
			{
				printf("%lld %lld\n",edg[k][1],edg[k][2]);
				sum+=edg[k][0];
				disunion(nfs,r1,r2);
			}			
		}
		printf("Weight of MST: %lld\n",sum);	
	return 0;
}
