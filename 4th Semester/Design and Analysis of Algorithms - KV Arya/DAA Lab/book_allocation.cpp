#include <iostream>
#include<vector>
using namespace std;

#define int long long

bool valid_page_allocation(vector<int> v, int mid, int n, int k){
    int sum = 0, students=1;

    for(int i=0; i<n; i++){
        sum += v[i];
        if(sum > mid){
            sum = v[i];
            students++;
        }
        if(students > k) {
            return false;
        }   
    }
    return true;
}

signed main(){
    int n;
    cout << "Total number of books: ";
    cin >> n;

    vector<int> v(n);
    int end=0;
    for(int i=0; i<n; i++){
        cout << "Number of pages in book " << i+1 << ": ";
        cin >> v[i];
        end+=v[i];
    }

    int k;
    cout << "Total number of students: ";
    cin >> k;

    int start = v[n-1], result = -1;
    
    if(n < k){
        cout << "Distribution not possible; As number of students is greater than number of books.\n" << endl;
        return 0;
    }

    while(start <= end){

        int mid = (start + end) / 2;

        if(valid_page_allocation(v, mid, n, k)){
            result = mid;
            end = mid - 1;
        }
        else    start = mid + 1;
        
    }
    if(result == -1)    cout << "Pages can't be divided." << endl;
    cout <<  "Maximum number of pages assigned to a student: " << result << endl;
}