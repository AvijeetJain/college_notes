#include <iostream>

using namespace std;
int main()
{
    int n = 0, temp, tt = 0, min, d, i, j;
    float atat = 0, awt = 0, stat = 0, swt = 0;

    cout << "enter no of process" << endl;
    n = 4;
    int a[4], b[4], e[4], tat[4], wt[4];

    cout << "enter arrival time ";
    for (i = 0; i < n; i++)
    {

        cin >> a[i];
    }

    cout << "enter brust time ";
    for (i = 0; i < n; i++)
    {
        // input
        cin >> b[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (b[i] > b[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    int ct[4];
    ct[0] = b[0];

    for (i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + b[i];
    }

    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - a[i];
        stat+=tat[i];
    }

    for (i = 1; i < n; i++)
    {
        wt[i] = tat[i] - b[i];
        swt+=wt[i];
    }

    cout << "Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n";

    for (i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "              " << a[i] << "                " << b[i] << "                  " << wt[i] << "               " << tat[i] << endl;
    }

    cout<<"Average Waiting Time : "<<swt/n<<endl;
    cout<<"Average Turn Around Time : "<<stat/n;
}