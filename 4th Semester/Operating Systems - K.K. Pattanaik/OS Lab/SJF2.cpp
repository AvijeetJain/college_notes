#include <stdio.h>
typedef struct sjf
{
    int process;    
    int burst;     
    int arrival; 
    int tct;   
    int tat;        
    int wt;         
}sjf;

int sort(sjf [], int);

int main()
{
    int n, i, temp = 0, AvTat = 0, AvWt = 0;

    printf ("Enter the number of processes: ");
    scanf ("%d", &n);
    sjf arr[n];   
    for (i = 0; i < n; i++)
    {
        arr[i].process = i+1;
        printf ("Enter the process %d data\n", arr[i].process);
        printf ("Enter CPU Burst: ");
        scanf ("%d", &(arr[i].burst));
        printf ("Enter the arrival time: ");
        scanf ("%d", &(arr[i].arrival));
    }
    
    printf ("Process\t\tArrival Time\t\tBurst Time\tCompletion Time\t\tTurn Around Time\t\tWaiting Time\n");
    arr[0].tct = arr[0].arrival + arr[0].burst;
    arr[0].tat = arr[0].tct - arr[0].arrival;
    arr[0].wt = arr[0].tat - arr[0].burst;
    AvTat = AvTat + arr[0].tat;
    AvWt = AvWt + arr[0].wt;
    printf ("%5d\t%15d\t\t%9d\t\t%12d\t\t%12d\t\t%12d\n", arr[0].process, arr[0].arrival,arr[0].burst,arr[0].tct,arr[0].tat, arr[0].wt);
    sort(arr, n);
    for (i = 1; i < n; i++)
    {
        temp = arr[i-1].tct;
        arr[i].tct = temp + arr[i].burst;
        arr[i].tat = arr[i].tct - arr[i].arrival;
        arr[i].wt = arr[i].tat - arr[i].burst;
        AvTat = AvTat + arr[i].tat;
        AvWt = AvWt + arr[i].wt;
        printf ("%5d\t%15d\t\t%9d\t\t%12d\t\t%12d\t\t%12d\n", arr[i].process, arr[i].arrival,arr[i].burst,arr[i].tct,arr[i].tat, arr[i].wt);
    }

    printf ("Average Turn Around Time: %d\nAverage Waiting Time: %d\n", AvTat / n, AvWt / n);
    
    return 0;
}
int sort(sjf arr[], int n)
{
    int i, j;
    sjf k;

    for (i = 1; i < n ; i++)
    {
        for (j = i + 1; j < n-1; j++)
        {
            if (arr[i].burst > arr[j].burst)
            {
                k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
        }
    }
 return 0;
}