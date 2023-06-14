#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cout << "Enter the size of the array 1: ";
    cin >> m;
    cout << "Enter the size of the array 2: ";
    cin >> n;

    cout << endl;

    int arr1[m],arr2[n], arr[m+n];

    cout << "Enter the elements of the array 1: ";
    for(int i=0;i<m;i++) {
        cin >> arr1[i];
    }

    cout << "Enter the elements of the array 2: ";
    for(int i=0;i<n;i++) {
        cin >> arr2[i];
    }
    cout << endl;

    
    int i=0,j=0,k=0;
    while (i<m && j<n) 
    {
        if(arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        
        else
            arr[k++] = arr2[j++];
    }
    

    while (i<m)
        arr[k++] = arr1[i++];
    
    while (j<n)
        arr[k++] = arr2[j++];

    
    cout << "The resultant array is: ";
    for(int element: arr)
        cout << element << " ";
    cout << endl << endl;

    int z;
    cout << "Enter the random index z: ";
    cin >> z;

    if(z>0 && z<n+m-1)
        cout << "The nearest elements are: " << arr[z-1] << " " << arr[z] << " " << arr[z+1];
    
    else if(z==0)
        cout << "The nearest elements are: "  << arr[z] << " " << arr[z+1] << " " << arr[z+2];
    
    else if(z==n+m-1)
        cout << "The nearest elements are: "  << arr[z-2] << " " << arr[z-1] << " " << arr[z];

    return 0;
}