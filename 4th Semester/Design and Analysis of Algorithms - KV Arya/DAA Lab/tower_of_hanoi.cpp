#include <iostream>

using namespace std;
  
void towerOfHanoi(int n, char source, char dest, char helper)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, source, helper, dest);
    cout << "Move disk " << n << " from " << source
         << " -> " << dest << endl;
    towerOfHanoi(n - 1, helper, dest, source);
}
  
// Source - Rod A
// Destination - Rod C
// Helper - Rod B
int main()
{
    int N = 3;
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}