#include <iostream>

using namespace std;
void tower_of_hanoi(int num, string source, string dest, string helper) {
    if (num==0){
        cout<<"no discs to move";
        return;
    }
    
    if (num == 1) {
    cout << " Move disk 1 from tower " << source << " -> " << dest << endl;
    return;
    }
    
    tower_of_hanoi(num - 1, source, helper, dest);
    cout << " Move disk " << num << " from tower " << source << " -> " << dest << endl;
    tower_of_hanoi(num - 1, helper, dest, source);
}
int main() {
  int num;
  cout<<"Enter no of disc : ";
  cin >> num;
  printf("The sequence of moves :\n");
  tower_of_hanoi(num, "I", "III", "II");
  return 0;
}