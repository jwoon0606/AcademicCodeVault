#include <iostream>
using namespace std;

int binsearch(int A[], int key, int size)
{
    int mid, left, right;

    left = 0;
    right = size - 1;
    while (1)
    {
        mid = (left + right) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            right = mid - 1;
        else if (key > A[mid])
            left = mid + 1;
        if (left > right)
            break;
    }

    return -1;
}

int main()
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int targetNum;
    int resultNum;

    cout << "Enter the number you want to find: ";
    cin >> targetNum;
    resultNum = binsearch(array, targetNum, 10);

    cout << "Target number: " << targetNum << endl
         << "Result number: " << resultNum << endl;
}