// Write the program to find the top 2 minimum and maximum element of the array with their index/location 
// from the given array where the elements are generated using random number generator. Make the three possible cases
// for n = 100, 200 and 300.


#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        { 
            if (arr[j] > arr[j + 1]) 
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main(void) {

    srand(time(0));
    
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n],tempArr[n];
    for(int i=0;i<n;i++) {
        arr[i] = rand() % 100;
        tempArr[i] = arr[i];
    }

    cout << "The random numbers are: ";
    for(int element: arr) {
        cout << element << " ";
    }

    bubbleSort(arr, n);

    int maxi, mini;
    for(int i=0;i<n;i++) {
        if(tempArr[i] == arr[n-1])
            maxi = i;
        
        if(tempArr[i] == arr[0])
            mini = i;
    }

    cout << endl << endl;
    cout << "The largest element in the array is: " << arr[n-1] << " at the index: " << maxi << endl;
    cout << "The smallest element in the array is: " << arr[0] << " at the index: " << mini << endl;

    for(int i=0;i<n;i++) {
        if(tempArr[i] == arr[n-2])
            maxi = i;
        
        if(tempArr[i] == arr[1])
            mini = i;
    }

    cout << endl << endl;
    cout << "The 2nd largest element in the array is: " << arr[n-2] << " at the index: " << maxi << endl;
    cout << "The 2nd smallest element in the array is: " << arr[1] << " at the index: " << mini << endl;
    return 0;
}