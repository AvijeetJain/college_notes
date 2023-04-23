#include<iostream>
using namespace std;

int main()
{

    int A[6]={-4,-2,0,1,4,5};
    int B[6]={-3,-1,1,6,8,9};

    int n=6;

    int MergedArr[12];

    int i = 0, j = 0, k = 0;
    while (i < n && j < n)

    {

        if (A[i] <= B[j])

        {
            MergedArr[k] = A[i];
            i = i + 1;
            k = k + 1;
        }

        else

        {
            MergedArr[k] = B[j];
            j = j + 1;
            k = k + 1;
        }
    }

    while (i < n)

    {
        MergedArr[k] = A[i];
        i = i + 1;
        k = k + 1;
    }

    while (j < n)

    {
        MergedArr[k] = B[j];
        j = j + 1;
        k = k + 1;
    }

    cout<<"MERGED ARRAY :"<<endl;
    for(int i=0; i<12; i++){
        
        cout<< MergedArr[i]<<"  ";
    }
    cout<<endl;

    cout<<(double)(MergedArr[n - 1] + MergedArr[n]) / 2;

    return 0;
}

