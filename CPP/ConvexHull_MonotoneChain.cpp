#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int,int>
#define PB push_back
#define MP make_pair
#define F first
#define S second

vector< pii > vp,upper,lower;
int n;
void display(){ for(int i=0;i<vp.size();i++) cout<<vp[i].F<<" "<<vp[i].S<<endl; }

int cross(pii p1, pii p2)
{
    int temp = p1.F*p2.S - p1.S*p2.F;
    if(temp==0)
        return 0;
    if(temp>0)
        return 1;
    return -1;
}

pii vect(pii p1, pii p2)
{
    pii p = MP(p1.F-p2.F, p1.S-p2.S);
    return p;
}

int main()
{
    int x,y,h;
    pii p;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        vp.PB(MP(x,y));
    }
    sort(vp.begin(),vp.end());

    //upper layer formation
    upper.PB(vp[0]);
    h=0;
    for(int i=1;i<n;i++)
    {
        p = vp[i];
        upper.PB(p);
        h++;
        while(upper.size()>2 && cross(vect(upper[h-1],upper[h-2]),vect(upper[h],upper[h-1]))>=0)
        {
            upper.pop_back();
            upper.pop_back();
            upper.PB(p);
            h--;
        }
    }

    //lower layer formation
    lower.PB(vp[n-1]);
    h=0;
    for(int i=n-2;i>=0;i--)
    {
        p = vp[i];
        lower.PB(p);
        h++;
        while(lower.size()>2 && cross(vect(lower[h-1],lower[h-2]),vect(lower[h],lower[h-1]))>=0)
        {
            lower.pop_back();
            lower.pop_back();
            lower.PB(p);
            h--;
        }
    }

    //printing points of convex hull 
    cout<<"Points of convex hull starting from lower bottom point in a clockwise order: ";
    for(int i=0;i<int(upper.size())-1;i++)
    {
        cout<<"("<<upper[i].F<<","<<upper[i].S<<") ";
    }
    for(int i=0;i<int(lower.size())-1;i++)
    {
        cout<<"("<<lower[i].F<<","<<lower[i].S<<") ";
    }
    cout<<endl;
    return 0;
}
