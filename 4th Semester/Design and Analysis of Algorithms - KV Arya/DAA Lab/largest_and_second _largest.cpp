#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int main(void) {

    srand(time(0));
    
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++) {
        arr[i] = rand() % 100;
    }

    cout << "The random numbers are: ";
    for(int element: arr) {
        cout << element << " ";
    }

    int max, min, maxi1, mini1, mini2, maxi2;

    max = arr[0];
    min = arr[0];
    maxi1 = 0;
    mini1 = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] > max) {
            max = arr[i];
            maxi1 = i;
        }

        if(arr[i] < min) {
            min = arr[i];
            mini1 = i;
        }
    }

    cout << endl << endl;
    cout << "The largest element in the array is: " << max << " at the index: " << maxi1 << endl;
    cout << "The smallest element in the array is: " << min << " at the index: " << mini1 << endl;
    
    max = arr[0];
    min = arr[0];
    for(int i=0;i<n;i++) {
        if(arr[i] > max && i != maxi1) {
            max = arr[i];
            maxi2 = i;
        }

        if(arr[i] < min && i != mini2) {
            min = arr[i];
            mini2 = i;
        }
    }

    cout << endl << endl;
    cout << "The 2nd largest element in the array is: " << max << " at the index: " << maxi2 << endl;
    cout << "The 2nd smallest element in the array is: " << min << " at the index: " << mini2 << endl;
    return 0;
}