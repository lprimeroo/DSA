//double hashing

#include<stdio.h>
#include<stdbool.h>
#define M 20

struct DataItem
{
    int key;
    int value;
} HT[M];

void initialize()
{
    for(int i = 0 ; i< M ; i++)
    {
        HT[i].key = 0;
    }
}

float loadFactor()
{
    int count = 0;
    for(int i = 0 ; i< M ; i++)
    {
        if(HT[i].key!=0)
        count++;
    }
    float d = (float)count/M;
    return d;

}

int hf1( int key )
{
    return key % M;
}

int hf2 ( int key )
{
    int k = 6 ;
    return (key % k) + 1;
}

void insertValue( int key )
{
    if(loadFactor()==1)
    {
        printf("HASHTABLE FULL");
        return;
    }

    int ha = hf1(key);
    int ha2 = hf2(key);

    if(HT[ha].key==0)
    {
       HT[ha].key = key;
       return;
    }

    int j = 1;
    int nha = ha + j*ha2 ;
    int k = nha % M ;

    while(j<90)
    {
        if(HT[k].key==0)
        {
            HT[k].key = key;
            return;
        }
        else
        {
            j++;
        }
    }

}

bool search( int key )
{
    int flag = 0;
    if(!loadFactor())
    {
        printf("NO ITEMS");
        return false;
    }

    int ha = hf1( key );
    int ha2 = hf2(key);

    if( HT[ha].key == key)
    {
        printf("FOUND");
        flag++;
        return true;
    }
    else
    {
        int j = 1;
        int nha = ha + j* ha2;
        int k = nha%M;

        while(j<90)
        {
            if(HT[k].key == key)
            {
                printf("FOUND");
                flag++;
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
    insertValue(34);
    insertValue(55);
    insertValue(12);
    insertValue(8);
    insertValue(45);
    insertValue(37);
    insertValue(88);
    insertValue(98);
    insertValue(54);
    insertValue(32);
    print();
    search( 34);


}



