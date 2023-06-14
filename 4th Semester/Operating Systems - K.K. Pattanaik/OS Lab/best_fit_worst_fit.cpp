#include <bits/stdc++.h>
using namespace std;
#define ll long long
void nextfit(vector<int> FreeSpace, int NewProccess, int LastIndex)
{
    int n = FreeSpace.size();

    for (int i = LastIndex + 1; i < n; i++)
    {
        if (FreeSpace[i] >= NewProccess)
        {
            cout << "Process No : " << i + 1 << endl;
            cout << "Free Space size : " << FreeSpace[i] << endl;
            return;
        }
    }
    cout << "No Memory to Allocated" << endl;
    return;
}
void worstfit(vector<int> FreeSpace, int NewProccess)
{
    int n = FreeSpace.size();
    int ind = -1;
    int mn = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (FreeSpace[i] >= NewProccess)
        {
            if (mn < FreeSpace[i])
            {
                ind = i;
                mn = FreeSpace[i];
            }
        }
    }
    if (ind == -1)
    {
        cout << "No Memory to Allocated" << endl;
        return;
    }
    cout << "Process No : " << ind + 1 << endl;
    cout << "Free Space size : " << FreeSpace[ind] << endl;
}
void bestfit(vector<int> FreeSpace, int NewProccess)
{
    int n = FreeSpace.size();

    int ind = -1;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (FreeSpace[i] >= NewProccess)
        {
            if (mn > FreeSpace[i] - NewProccess)
            {
                ind = i;
                mn = FreeSpace[i] - NewProccess;
            }
        }
    }
    if (ind == -1)
    {
        cout << "No Memory to Allocated" << endl;
        return;
    }
    cout << "Process No : " << ind + 1 << endl;
    cout << "Free Space size : " << FreeSpace[ind] << endl;
}
void firstfit(vector<int> FreeSpace, int NewProccess)
{
    int n = FreeSpace.size();

    for (int i = 0; i < n; i++)
    {
        if (FreeSpace[i] >= NewProccess)
        {
            cout << "Process No : " << i + 1 << endl;
            cout << "Free Space size : " << FreeSpace[i] << endl;
            return;
        }
    }
    cout << "No Memory to Allocated" << endl;
    return;
}
int main()
{
    vector<int> FreeSpace = {8, 12, 22, 18, 6, 14, 32};
    int NewProccess = 16;
    int LastAllocatedProcess = 4;
    cout << "First Fit" << endl;
    firstfit(FreeSpace, NewProccess);
    cout << "Best Fit" << endl;

    bestfit(FreeSpace, NewProccess);
    cout << "Worst Fit" << endl;
    worstfit(FreeSpace, NewProccess);
    cout << "Next Fit" << endl;
    nextfit(FreeSpace, NewProccess, LastAllocatedProcess);
}