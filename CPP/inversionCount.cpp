#include<iostream>
using namespace std;
int getInversionCount(int arr[],int n){
  int inversionCount = 0;
  for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
        if(arr[i]>arr[i+1])
          inversionCount++;
      }      
  }
  return inversionCount;
}

// int main(){
//   int n;
//   cin >> n;
//   int arr[n];
//   cout << "Enter the elements for the array";
//   for(int i=0;i<n;i++){
//     cin >> arr[i];
//   }
//   cout << "Number of inversion count is";
//   getInversionCount(arr,n);
int main(){
  int arr[] = { 1, 20, 6, 4, 5 };
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << " Number of inversions are "
       << getInversionCount(arr, n);
  return 0;
}
