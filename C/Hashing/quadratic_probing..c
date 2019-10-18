//quadratic probing

#include<stdio.h>
#include<stdbool.h>

#define M 15

struct DataItem
{
    int key;
    int value;
} HT[M];


void initialize()
{
    for(int i = 0 ; i < M ; i++)
    {
        HT[i].key = 0;
    }
}

float loadFactor()
{
    int count = 0;
    for(int i = 0 ; i< M ; i++)
    {
        if( HT[i].key != 0)
        {
            count++;
        }
    }
        float d = (float)count/M;
        return (float)d;
}


void insert(int item)
{
    int j = 1;
    if(loadFactor() == 1)
    {
        printf("HASH TABLE FULL\n");
        return;
    }

    int ha = item % M;
    if( HT[ha].key == 0 )
    {
         HT[ha].key = item;
         return;
    }

    while(true)
    {
        int nha = ha + (j*j);
        int k = nha % M;
        if (HT[k].key == 0)
        {
            HT[k].key = item;
            return;
        }
        else
        {
            j++;
        }
    }

}


bool search(int item)
{
    int flag = 0;
    int j = 1;
    if(!loadFactor())
    {
        printf("NO ITEMS");
        return false;
    }
    int ha = item % M;
    if(HT[ha].key == item)
    {
        printf("FOUND");
        return true;
    }

    while(j < 10)
    {
        int nha = ha + (j*j);
        int k = nha % M;
        if(HT[k].key == item)
        {
            printf("FOUND");
            flag = 1;
            return true;
        }
        else
        {
            j++;
        }
    }
    if(!flag)
        {
            printf("NOT FOUND");
            return false;
        }
}


bool deleted(int item)
{
    int j = 1;
    if(!loadFactor())
    {
        printf("NO ITEMS");
        return false;
    }

    int ha = item % M;
    if( HT[ha].key == item)
    {
        HT[ha].key = 0;
        return true;
    }

    while(j<10) /////////////////////
    {
        int nha = ha + (j*j);
        int k = nha % M;

        if( HT[k].key == item)
        {
            HT[k].key = 0;
            return true;
        }
        else
        {
            j++;
        }
    }
    printf("NOT FOUND\n");
    return false;

}

void print()
{
    for(int i = 0  ; i< M ; i++)
    {
        printf("%5d" , HT[i].key);
    }
    printf("\n");
}




int main()
{
    int choice;
    int key;
    printf("*************QUADRATIC PROBING***************\n");
    printf("1. Insert\n2. Search\n3. Delete\n4. Print\n0. Exit\n");
    do
    {
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the Number To be Inserted: ");
                scanf("%d" , &key);
                insert(key);
                break;
            case 2:
                printf("\nEnter the Number To be Searched: ");
                scanf("%d" , &key);
                search(key);
                break;
            case 3:
                printf("\nEnter the Number To be Deleted: ");
                scanf("%d" , &key);
                deleted(key);
                break;
            case 4:
                printf("\n");
                print();
                break;
            default:
                printf("WRONG INPUT");
        }
    }while(choice!= 0);
}
