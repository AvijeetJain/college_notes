#include<iostream>
using namespace std;

int main()
{
    int A[6];
    int B[5];
    
    cout<<"Enter elements in the 1st Array : ";
    for(int m=0; m<6; m++){
        cin>>A[m];
    }
    
    cout<<"Enter elements in the 2st Array : ";
    for(int n=0; n<5; n++){
        cin>>B[n];
    }

    // int A[6]={-4,-2,0,1,4,5};
    // int B[5]={-3,-1,1,6,8};

    int m=6;
    int n=5;

    int MergedArr[11];

    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
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

    while (i < m)
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
    for(int i=0; i<11; i++){
        
        cout<< MergedArr[i]<<"  ";
    }
    cout<<endl;

    int z;
    cout<<"Enter a random position z : ";
    cin>>z;


    cout<<"3 nearest Random Elements : ";
    if(z==m+n-1){
        cout<<MergedArr[m+n-2]<<"  "<<MergedArr[m+n-3]<<"  "<<MergedArr[m+n-4]<<endl;
    }

    else if(z==0){
        cout<<MergedArr[1]<<"  "<<MergedArr[2]<<" "<<MergedArr[3]<<endl;
    }

    else if(z==1) {
        cout<<MergedArr[0]<<"  "<<MergedArr[z+1] << "  " << MergedArr[z+2]<<endl;
    }

    else if(z==m+n-2){
        cout<<MergedArr[m+n-1] << "  " << MergedArr[m+n-3] << "  " << MergedArr[m+n-4] <<endl;
    } 

    else{
        cout<<MergedArr[z-1]<< "  " << MergedArr[z+1] << "  " << MergedArr[z+2]<< endl;
    }
    return 0;
}

