//Ternary Search can find the maximum or minimum value of unimodal function.
//Leonardo Su , Github : @leonardosu

#include <bits/stdc++.h>
using namespace std;
const int N = 100010; // length of array
int Array[N];

// Return the position of the value in the range [l,r]
int Ternary_search(int l,int r, int x) //l = begin, r = end , x = value
{
	int middle1,middle2; //left and right part

    while(l <= r)
    {
        middle1 = (2*l + r)/3;
        middle2 = (l + 2*r)/3;

        if(Array[middle1] == x)
            return middle1;

        if(Array[middle2] == x)
            return middle2;

        if(x<Array[middle1]) // go to 
        	r = middle1 - 1;

        else if(x>Array[middle2])
        	l = middle2 + 1;

        else
        	l = middle1 + 1, r = middle2 - 1;
    }

    return -1; // If don't find 
}

int main()
{

}