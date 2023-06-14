// C++ implementation of First - Fit algorithm
#include<bits/stdc++.h>
using namespace std;
 
void firstFit(int blockSize[], int m,
              int processSize[], int n)
{
    int allocation[n];
 
    memset(allocation, -1, sizeof(allocation));
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
 
                break;
            }
        }
    }
 
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t"
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
int main()
{
    int blockSize[] = {8, 12, 22, 18, 6, 14, 32};
    int processSize[] = {16};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
 
    firstFit(blockSize, m, processSize, n);
 
    return 0 ;
}