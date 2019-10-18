//open hashing

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define M 5

struct Node
{
    int key;
    struct Node* next;
};

struct Hash
{
    struct Node* head;
    int count;
} *HT;

struct Node* createNode( int key )
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
};

void initialize()
{
    for ( int i = 0 ; i < M ; i++)
    {
        HT[i].head = NULL;
    }
}

void insertValue( int key )
{
    int ha = key % M;
    struct Node* newNode = createNode( key );

    if(!HT[ha].head)
    {
        HT[ha].head = newNode;
        HT[ha].count = 1;
    }
    else
    {
        newNode->next = HT[ha].head;
        HT[ha].head = newNode;
        HT[ha].count++;
    }
}

bool search( int key )
{
    int ha = key % M;
    int flag = 0;

    if(!HT[ha].head)
    {
        printf("NOT FOUND");
        return false;
    }

    for( struct Node* temp = HT[ha].head ; temp!=NULL ; temp = temp->next)
    {
        if( temp->key == key)
        {
            printf("FOUND");
            return true;
        }
    }
    printf("NOT FOUND");
    return false;

}


void print()
{
    for( int i=0; i < M ; i++ )
    {
       printf("\nentries at index %d\n",i);
       if(!HT[i].head)
       {
           printf("NULL");
           return;
       }
       else
       {
          for(struct Node* temp = HT[i].head ; temp!=NULL ; temp = temp->next)
            printf("%2d->",temp->key);
       }
    }

}

int main()
{
   HT = (struct Hash*) calloc( M , sizeof(struct Hash));
   insertValue(5);
   insertValue(10);
   insertValue(6);
   insertValue(7);
   insertValue(8);
   insertValue(9);
   insertValue(11);
   insertValue(12);
   insertValue(13);
   insertValue(14);
   print();
   printf("\n");
   int s = 8;
   printf("%d ->> " , s);
   search(s);
}



