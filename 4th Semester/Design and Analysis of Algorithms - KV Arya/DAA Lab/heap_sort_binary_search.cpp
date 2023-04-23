// Daa Lab Major
// Name: Avijeet Jain
// Roll No.: 2021IMG-018

// --------------------------------------- Set - 1 ------------------------------------

// Question: Given an array of n elements sort tht the array in decreasing order using heap and then search the element 
// using binary search. Write a program to solve the given problem by taking the user input for n, elements of array and 
// provide the pseudo code, analysis of the problem on this page.

#include<iostream>
using namespace std;

// ----------------------------- Code for heap sort starts here ------------------------

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
  
void heapify(int arr[], int n, int i) {
    int max = i; 
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
  

    if (leftChild < n && arr[leftChild] > arr[max])
      max = leftChild;
  
    if (rightChild < n && arr[rightChild] > arr[max])
      max = rightChild;
  
    if (max != i) {
      swap(&arr[i], &arr[max]);
      heapify(arr, n, max);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
 
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      heapify(arr, i, 0);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
}
// ----------------------------- Code for heap sort ends here ------------------------


// ------------------------ Code for Binary Seach starts here ------------------------
int binarySearch(int arr[], int p, int r, int num) {
   if (p <= r) {
      int mid = (p + r)/2;
      if (arr[mid] == num)
         return mid ;
      if (arr[mid] > num)
         return binarySearch(arr, p, mid-1, num);
      if (arr[mid] < num)
         return binarySearch(arr, mid+1, r, num);
   }
   return -1;
}
// ------------------------- Code for Binary Seach ends here -------------------------


int main() {
    int arr[1000];
    int n;
    cout<<"Enter no. of elements to enter in the Array: ";
    cin>>n;

    cout<<"Enter "<<n<<" elements: ";
    for(int a=0; a < n; a++){
        cin>>arr[a];
    }

    // int arr[] = {11, 34, 9, 5, 16, 10};
    // int n = sizeof(arr) / sizeof(arr[0]);
	
    cout<<"-----------------------"<<endl;

    cout<<"Original Array: ";
    display(arr, n);
    heapSort(arr, n);

    cout<<"-----------------------"<<endl;

    cout<<"Sorted Array: ";
    display(arr, n);
    cout<<"-----------------------"<<endl;

//  for binary seach 

    int num;
    cout << "Enter the number to search in the Sorted Array: ";
    cin >> num;

    int index = binarySearch (arr, 0, n-1, num);
    
    cout<<endl;
    
    if(index == -1){
        cout<< num <<" is not present in the array.";
    }else{
        cout<< "Index of "<< num <<" in the array : "<< index;
    }
}



// int main() {
//    int arr[] = {1, 3, 7, 15, 18, 20, 25, 33, 36, 40};
//    int n = sizeof(arr)/ sizeof(arr[0]);
//    int num;

//    cout << "Enter the number to search in the Sorted Array: ";
//    cin >> num;

//    int index = binarySearch (arr, 0, n-1, num);
//    if(index == -1){
//       cout<< num <<" is not present in the array.";
//    }else{
//       cout<< num <<" is present at index value "<< index <<" in the array.";
//    }
//    return 0;
// }















