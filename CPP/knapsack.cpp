/* 0/1 knapsack using dynamic programming */
#include<iostream>
using namespace std;

int knapsack(int W, int wt[], int value[], int N) {
    int i,j;
    int k[N+1][W+1];

    for(i=0; i<=N; i++) {
        for(j=0; j<=W; j++) {
            if(i == 0 || j == 0) {
                k[i][j] = 0;
            }
            else if(wt[i-1] <= j) {
                k[i][j] = max(value[i-1] + k[i-1][j-wt[i-1]], k[i-1][j]);
            }
            else {
                k[i][j] = k[i-1][j];
            }
        }
    }
    return k[N][W];
}

int main() {
    int N = 3;
    int value[N] = {40, 20, 100, 60};
    int weight[N] = {1, 2, 3, 4};
    int maxCapacity = 5;
    
    cout << knapsack(maxCapacity, weight, value, N);

    return 0;
}
