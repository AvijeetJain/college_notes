#include<iostream>
using namespace std;

void printArray(int *arr, int n){
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
	int processes[] = {1,2,3,4,5};
	int arrivalTime[] = {0,1,2,3,4};
	int burst_time[] = {2,3,4,5,1};

	int n = 5;

    int completion_time[5];
    int sum = 0;
    for(int i=0;i<5;i++)
    {
        completion_time[i] = sum + burst_time[i];
        sum += burst_time[i];
    }
    cout << "Completion Time: ";
    printArray(completion_time,n);

    int wait_time[5];
    wait_time[0] = 0;
    for(int i=1;i<5;i++)
    {
        wait_time[i] = wait_time[i-1] + arrivalTime[i];
    }
    cout << "Wait Time: ";
    printArray(wait_time,n);

    int turnAroundTime[5];
    for(int i=0;i<5;i++)
    {
        turnAroundTime[i] = burst_time[i] + wait_time[i];
    }
    cout << "Turn Around Time: ";
    printArray(turnAroundTime,n);
	return 0;
}