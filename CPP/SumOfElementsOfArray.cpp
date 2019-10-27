#include<iostream>

using namespace std;

//function magically returns sum starting from i

int sumArray(int arr[],int n,int i){

    if(i==n-1){

        return arr[n-1];

    }

    int right = sumArray(arr,n,i+1);

    return arr[i]+right;

}

int main(){
	int n;
	cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
	}
    cout<<sumArray(arr,n,0);

}
