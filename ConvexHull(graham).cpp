/*C++ implementation to find convex hull of a set of points*/

#include <iostream>
#include <stack>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
 
struct Point
{
    int x, y;
};
 
// A globle point for  sorting points with reference
// to  the first point 
Point p0;
 
//find next on top in a stack
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 

int swap(Point &t1, Point &t2)
{
    Point temp = t1;
    t1 = t2;
    t2 = temp;
}
 
// Calculate square of distance
// between t1 and t2
int distSq(Point t1, Point t2)
{
    return (t1.x - t2.x)*(t1.x - t2.x) +
          (t1.y - t2.y)*(t1.y - t2.y);
}
 
// orientation of ordered triplet (p, q, r).

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// Function used by qsort() to sort an array of
// points with respect to the first point
int compare(const void *cp1, const void *cp2)
{
   Point *p1 = (Point *)cp1;
   Point *p2 = (Point *)cp2;
 
   
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}
 

void convexHull(Point points[], int n)
{
   // bottommost point
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
 
     // bottom-most or  left
     // most point in case of tie
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   // Place the bottom-most point at first position
   swap(points[0], points[min]);
 
   // Sort n-1 points with respect to the first point.
   
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
 
   
   int m = 1; // for modified array
   for (int i=1; i<n; i++)
   {
       
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;
 
 
       points[m] = points[i];
       m++;  // Update modified array
   }
 
   // If modified array of points has less than 3 points,
   // convex hull is not possible
   if (m < 3) return;
 
   // Create an empty stack and push first three points
   // to it.
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      

      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
 
  

   while (!S.empty())
   {
       Point p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }
}
 

int main()
{
    Point points[100000] ;
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<"Enter the set of elements:";
    for(int i = 0;i<n;i++)
    {
    	cin>>points[i].x;
    	cin>>points[i].y;
    }
    convexHull(points, n);
    return 0;
}