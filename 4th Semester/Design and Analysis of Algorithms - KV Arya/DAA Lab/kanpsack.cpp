#include <iostream>
#include <algorithm>
using namespace std;


int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}

int main() {
    int n,W;
    cout<<"Enter the no of items: ";
    cin>>n;
    cout<<"Enter the weight of bag: ";
    cin>>W;
    int val[n],wt[n];
    cout<<"Enter the value array :";
    for (int i = 0; i < n; i++)
    {
        cin>>val[i];
    };
    cout<<"Enter the weight array :";
    for (int i = 0; i < n; i++)
    {
        cin>>wt[i];
    };
    cout << "Maximum value = " << knapsack(W, wt, val, n) << endl;
    return 0;
}

