
/*Shell Sort
Written by Chaitya Shah
*/
#include<iostream>
#include<stdlib.h> /* for malloc and calloc */
#include<ctime>  /*for execution time */
using namespace std;
int start_watch;
typedef long long datatype;  //replace long long with desired datatype
int h_sort(datatype *A,datatype N,datatype h){
    datatype pointer;
    datatype temp;
     for(datatype i=h;i<N;i++){
         pointer = i;     //index of the element it will insert in the correct place
            temp = A[i];
        while(temp<A[pointer-h] && pointer>=h){
            A[pointer] = A[pointer-h];
            pointer-= h;
        }
        A[pointer] = temp;
    }
    return 0;
}


int shell_sort(datatype *A,datatype N){
    start_watch = clock();
    datatype h = 4;
    //while(h < N/3) h = (h*3)+1;    /*  Hibbard, 1963  sequence for shell sort (Not working on my device) */
    while(h>=1){
        //h = h/3;
        h_sort(A,N,h);     /*h sorting for h = 4 and h = 1 still increases speed  */
        //cout<<"IT worked uptill here"<<endl;
        h = h/3;
    }
    return 0;
}

int main(){

    /* Taking input */
    datatype *A,N;
    //cout<<"Enter the number of elements in the array: ";
    //cin>>N;
    N = 200000; //enter the numberOFTestCases here
    A = (datatype *) calloc(N,sizeof(datatype));      //can also be A = (datatype *) malloc(N*sizeof(datatype));
    for(datatype i = 0;i<N;i++) cin>>A[i];

    /*Shell Sort  */
    shell_sort(A,N);
    for(datatype i=0;i<N;i++) cout<<"\n"<<A[i]<<" ";
    free(A);
    float stop_watch = clock();
    cout<<"\n Execution time :   "<<(stop_watch-start_watch)/CLOCKS_PER_SEC<<" seconds"<<endl;
    return 0;
}

