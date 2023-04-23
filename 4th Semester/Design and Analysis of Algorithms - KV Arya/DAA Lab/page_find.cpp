#include <iostream>
using namespace std;

int findPages(int arr[], int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int minPages = sum / m;

    while (minPages <= sum)
    {
        int studentsRequired = 1;
        int curr_sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (curr_sum + arr[i] > minPages)
            {
                studentsRequired++;
                curr_sum = arr[i];
            }
            else
                curr_sum += arr[i];
        }

        if (studentsRequired <= m)
            return minPages;

        minPages++;
    }
    return -1;
}

int main()
{
    int arr[] = {12, 34, 67, 90, 98};
    int n = sizeof arr / sizeof arr[0];
    int m = 2;
    cout << "Minimum number of pages = " << findPages(arr, n, m) << endl;
    return 0;
}