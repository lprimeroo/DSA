// C++ implementation to find the smallest distance from a
// given set of points.
 
#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;
 

struct Point
{
    int x, y;
};
 
 

 
// sort array of points according to X coordinate
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}
// sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}
 

float dist(Point q1, Point q2)
{
    return sqrt( (q1.x - q2.x)*(q1.x - q2.x) +
                 (q1.y - q2.y)*(q1.y - q2.y)
               );
}
 
//Brute Force method applied
float bruteForce(Point Q[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(Q[i], Q[j]) < min)
                min = dist(Q[i], Q[j]);
    return min;
}
 

float min(float x, float y)
{
    return (x < y)? x : y;
}
 
 

// It is a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(Point strip[], int size, float d)
{
    float min = d;  
 
    
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
 
    return min;
}
 

float closestUtil(Point Px[], Point Py[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(Px, n);
 
    // Find the middle point
    int mid = n/2;
    Point midPoint = Px[mid];
 
 
    
    // Assumption: All x coordinates are distinct.
    Point Pyl[mid+1];   // y sorted points on left of vertical line
    Point Pyr[n-mid-1];  // y sorted points on right of vertical line
    int li = 0, ri = 0;  // index of left and right subarrays
    for (int i = 0; i < n; i++)
    {
      if (Py[i].x <= midPoint.x)
         Pyl[li++] = Py[i];
      else
         Pyr[ri++] = Py[i];
    }
 
    // As a vertical line is passing through the middle point
    // find the smallest distance dl on left of middle point and
    // dr on right side
    float dl = closestUtil(Px, Pyl, mid);
    float dr = closestUtil(Px + mid, Pyr, n-mid);
 
    

    float d = min(dl, dr);
 
    //  strip[] contains points close (closer than d)
    //  to the line 
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;
 
    

    return min(d, stripClosest(strip, j, d) );
}
 


float closest(Point P[], int n)
{
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
 
    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);
 
   

    return closestUtil(Px, Py, n);
}
 

int main()
{
    

    Point P[100000] ;
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<"Enter the set of elements:";
    for(int i = 0;i<n;i++)
    {
        cin>>P[i].x;
        cin>>P[i].y;
    }
    cout << "The smallest distance is " << closest(P, n);
    return 0;
}