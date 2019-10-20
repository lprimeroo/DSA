#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define M 3

struct DataItem
{
    int key;
    int value;
} HT[M];

void initialize()
{
    for(int i = 0 ; i<M ; i++)
    {
        HT[i].key = 0;
    }
}

bool search(int k)
{
    return HT[k%M].key == k;
}

float loadFactor()
{
    int count = 0 ;
    for(int i=0 ; i< M ; i++)
    {
        if( HT[i].key !=0)
            count++;
    }
        float d = (float)count/M;//////////////////
        return (float) d ;
}

void insert(int item)
{
    if(loadFactor() == 1) ///////////////
    {
       printf("TABLE FULL\n");
       return;
    }
    HT[item%M].key = item;
}

bool deleted(int item)
{
    if(!loadFactor())
    {
        printf("NO DATA FOUND\n");
        return false;
    }

    if(HT[item%M].key = item)
    {
        HT[item%M].key = 0;
        return true;
    }
    else
    {
        printf("NOT FOUND");
        return false;
    }
}

void print()
{
    for(int i = 0  ; i< M ; i++)
    {
        printf("%5d" , HT[i].key);
    }
}


int main()
{
    insert(11);
    insert(22);
    insert(21);
    printf("%d\n",search(11));
//    print();
//    printf("\n");
//    deleted(22);
//    deleted(11);
//    deleted(21);
//    deleted(20);
//    print();
}
