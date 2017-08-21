#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long int ll;
typedef vector< ll > vi;
int t,m,a,k,n,nr;
vi L(1001),T(1001);
int P[11][1001];


/// LCA <nlogn,logn> ///
///LCA for a tree 
///problem http://www.spoj.com/problems/LCA/

void prepro()
{
	int i,j;
	rep(i,n)
	{	
	     for (j = 0; 1 << j < n; j++)
	        P[j][i+1] = -1;
	}
  //the first ancestor of every node i is T[i]
      for (i = 0; i < n; i++)
          P[0][i+1] = T[i+1];

  //bottom up dynamic programing
      for (j = 1; 1 << j < n; j++)
         for (i = 1; i <= n; i++)
             if (P[j-1][i] != -1)
                 P[j][i] = P[j - 1][P[j-1][i]];

}

int LCA(int p ,int q)
{
    int tmp, log, i;
    if (L[p] < L[q])
        swap(p,q);
    for (log = 1; 1 << log <= L[p]; log++);
    log--;
    for (i = log; i >= 0; i--)
         if (L[p] - (1 << i) >= L[q])
              p = P[i][p];

    if (p == q)
        return p;
    for (i = log; i >= 0; i--)
        if (P[i][p] != -1 && P[i][p] != P[i][q])
            p = P[i][p], q = P[i][q];

    return T[p];
      
}

int main() {
   
    cin>>t;
    int q,x,y;
    rep(z,t)
    {
    	cin>>n;
    	k=1;L[1]=0;
    	rep(i,n+1)T[i]=1;
    	rep(i,n)
    	{
    		cin>>m;
    		L[i]=L[T[i]]+1;
    		L[1]=0;
    		rep(j,m)
         	{
    			cin>>a;
    			T[a]=i+1;
    			L[a]=L[T[a]]+1;
    		}
    	}
    	prepro();
    	cin>>q;
    	cout<<"Case "<<z+1<<":\n";
    	while(q--)
        {
            cin>>x>>y;
            cout<<LCA(x,y)<<'\n';
        }
    }
    return 0;
}

