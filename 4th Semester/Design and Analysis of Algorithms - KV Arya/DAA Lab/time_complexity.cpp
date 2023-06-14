#include<iostream>
using namespace std;

int main()
{
    int n = 4;
    cout << "O(1) notation:" << endl;
    cout << "Hello World" << endl;
    cout << endl << endl;

    cout << "O(n) notation:" << endl;
    for(int i=0;i<n;i++)
        cout << "Hello World" << endl;
    cout << endl << endl;

    cout << "O(log (n)) notation:" << endl;
    for(int i=1;i<n;i*=2)
        cout << "Hello World" << endl;
    cout << endl << endl;

    cout << "O(n log(n)) notation:" << endl;
    for(int i=0;i<n;i++)
        for(int j=1;j<n;j*=2)
            cout << "Hello World" << endl;
    cout << endl << endl;

    cout << "O(n^2) notation:" << endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout << "Hello World" << endl;
    cout << endl << endl;
    return 0;
}
