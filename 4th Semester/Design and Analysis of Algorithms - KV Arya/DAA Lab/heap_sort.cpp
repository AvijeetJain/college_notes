#include <iostream>
using namespace std;

class Heap
{
private:
    int *arr;
    int empty_pos;
    int size;

public:
    Heap(int sz)
    {
        arr = new int[sz + 1];
        for (int i = 1; i < sz + 1; i++)
        {
            arr[i] = -1;
        }
        size = sz + 1;
        empty_pos = 1;
    }
    void swap(int &p, int &q)
    {
        int temp = p;
        p = q;
        q = temp;
    }
    bool isFull() { return empty_pos == size + 1; }
    bool isEmpty() { return empty_pos == 1; }
    bool insert(int val)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            arr[empty_pos] = val;
            empty_pos++;
            return true;
        }
        arr[empty_pos] = val;
        empty_pos++;
        // Comparison starts with its parents
        int i = empty_pos - 1;
        while (i > 1)
        {
            if (arr[i] < arr[i / 2])
            {
                swap(arr[i], arr[i / 2]);
                i = i / 2;
            }
            else
            {
                break;
            }
        }
        return true;
    }

    void print_heap()
    {
        for (int i = 1; i < empty_pos; i++)
        {
            cout << i << " : " << arr[i] << endl;
        }
    }
    
    int index_of_max_of_children(int j)
    {
        if (arr[2 * j] > arr[2 * j + 1])
            return 2 * j;
        else
            return 2 * j + 1;
    }
    int pop()
    {
        if (isEmpty())
            return -1;
        int val = arr[1];
        int i = empty_pos - 1;
        swap(arr[1], arr[i]);
        empty_pos--;
        int j = 1;
        while (j > empty_pos && (2 * j > empty_pos && (2 * j + 1) > empty_pos))
        {
            int max = index_of_max_of_children(j);
            if (arr[j] < arr[max])
            {

                swap(arr[j], arr[max]);
                j = max;
            }
            else
            {
                break;
            }
        }
        return val;
    }
};

int main()
{
    Heap heap1(15);
    int arr[] = {17,15,13,10,9,8,6,5,4,3,1};
    for (int i = 0; i < 11; i++)
    {
        heap1.insert(arr[i]);
    }
    heap1.print_heap();
    int newarr[11];
    for (int i = 0; i < 11; i++)
    {
        newarr[i] = heap1.pop();
    }
    cout << "Sorted array is : " << endl;
    for (int i = 0; i < 11; i++)
    {
        cout << newarr[i] << " ";
    }
}