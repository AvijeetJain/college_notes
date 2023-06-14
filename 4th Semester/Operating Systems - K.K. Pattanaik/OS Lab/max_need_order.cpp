#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> all = {
        {7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    vector<vector<int>> maxNeed = {
        {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int n = 5;
    int totA = 10, totB = 5, totC = 7;
    int remA = 0, remB = 0, remC = 0;
    vector<vector<int>> rem(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        rem[i][0] = all[i][0] - maxNeed[i][0];
        rem[i][1] = all[i][1] - maxNeed[i][1];
        rem[i][2] = all[i][2] - maxNeed[i][2];
    }
    for (int i = 0; i < n; i++)
    {
        remA += maxNeed[i][0];
        remB += maxNeed[i][1];
        remC += maxNeed[i][2];
    }
    remA = totA - remA;
    remB = totB - remB;
    remC = totC - remC;
    int cnt = 0;
    int sign = 1;
    vector<int> ans;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (remA >= rem[j][0] && remB >= rem[j][1] && remC >= rem[j][2] && vis[j] == 0)
            {
                remA += maxNeed[j][0];
                remB += maxNeed[j][1];
                remC += maxNeed[j][2];
                cnt++;
                ans.push_back(j);
                vis[j] = 1;
                break;
            }
            if (cnt == n)
            {
                sign = 0;
            }
        }
    }
    cout << "Order" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "P" << ans[i]<<" ";
}
}