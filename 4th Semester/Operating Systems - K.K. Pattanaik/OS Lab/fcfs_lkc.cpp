#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> v = {
        {1, 0, 2},
        {2, 1, 3},
        {3, 2, 4},
        {4, 3, 5},
        {5, 4, 1}};
    int n = v.size();
    vector<int> ct(n, 0);
    vector<int> tat(n, 0);
    vector<int> wt(n, 0);
    ct[0] = v[0][2];
    for (int i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + v[i][2];
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - v[i][1];
    }
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - v[i][2];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ct[i] << " " << tat[i] << " " << wt[i] <<endl;
        }
}