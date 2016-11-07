//This is Huffman encoding on input string
// The input is the string to be encoded.
// THe outputs:-
// 1. The number of distinct letters for the code
// 2. The frequency of each distinct letter.
// 3. The code for each distinct letter.
// 4. The encoding of the input string
#include <iostream>
#include <fstream>
#include <strings.h>
#include <queue>
#include <stdlib.h>
using namespace std;
string code[128];

// The data node to build the tree.
struct dataCh
{
    char data;
    unsigned freq;
    dataCh *left, *right;
    dataCh(char data1,unsigned freq1)
    {
        this->data = data1;
        this->freq = freq1;
        this->left = NULL;
        this->right = NULL;
    }
};

// Custom compare function for the priority queue
struct compare
{
    bool operator() (dataCh *l,dataCh *r)
    {
        return l->freq>r->freq;
    }
};

// The encode function, that recursively builds the hash that stores the code.
void encodeIt(dataCh *root,string ch)
{
    if(!root)
        return;
    if(root->data != '@')
    {
        cout<<root->data<<" : "<<ch<<"\n";
        code[root->data] = ch;
        return;
    }
    encodeIt(root->left,ch+"0");
    encodeIt(root->right,ch+"1");
}

// The function that builds the tree.
void executeTree(char dataHe[],unsigned freqHe[],int n)
{
    dataCh *top;
    priority_queue<dataCh*,vector<dataCh*>,compare> q;
    for(int i=0; i<n; ++i)
        q.push(new dataCh(dataHe[i],freqHe[i]));
    while(q.size()!=1)
    {
        dataCh *lefty,* righty;
        lefty = q.top();
        q.pop();
        righty = q.top();
        q.pop();
        top = new dataCh('@',lefty->freq + righty->freq);
        top->left = lefty;
        top->right = righty;
        q.push(top);
    }

    // Call the function to generate the hash for the characters input
    encodeIt(q.top(),"");
    while(!q.empty())
        q.pop();
}
int main()
{
    char a[101];
    cout<<"\nEnter the string to be encoded\n";
    cin.getline(a,101);
    int p = strlen(a);
    int t[128] = {0};
    for(int i=0; i<p; ++i)
    {
        t[a[i]]++;
    }
    int countit = 0;
    for(int i=0; i<128; ++i)
    {
        if(t[i]!=0) countit++;
    }
    cout<<"\nThe number of distinct characters used is "<<countit<<"\n";
    int n = countit;
    char letter[n];
    unsigned freq[n];
    int st=0;
    for(int i=0; i<128; i++)
    {
        if(t[i]!=0)
        {
            letter[st] = char(i);
            freq[st++] = t[i];
        }
    }
    for(int i=0; i<n; ++i)
        cout<<"\nFrequency of "<<letter[i]<<" : "<<freq[i];
    cout<<"\nThe codes are \n";
    executeTree(letter,freq,n);
    cout<<"\nThe encoded string for "<<a<<" is \n";
    for(int i=0; i<p; ++i) cout<<code[a[i]];

    return 0;
}
