#include <iostream>
#include <vector>
using namespace std;

const int inf = 1e9;

int check_longest_increasing_subsequence(vector<int> &ar){
  int n = ar.size();
  vector<int> dp(n+1, inf);

  for(int i = 0; i < n; i++){
    *lower_bound(dp.begin(), dp.end(), ar[i]) = ar[i];
  }

  return lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}

int main(){
  vector<int> ar = {1,6,-3,0,3,4,2,1,6,7,8};

  cout << "original array is :";
  for(int i = 0; i < ar.size(); i++) cout << " " << ar[i];
  cout << endl;

  cout << "Longest Length of increasing subsequence is ";
  cout << check_longest_increasing_subsequence(ar) << endl;

  return 0;
}
