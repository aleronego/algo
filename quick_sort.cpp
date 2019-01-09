#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right)
{
    //cout << "q ";
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            ++i;
        while (arr[j] > pivot)
            --j;
        if (i <= j) {
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    if (left < i)
        quickSort(arr, left, j);
    if (right > j)
        quickSort(arr, i, right);
}

void printArr(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] { 4, 7, 6, 9, 8, 1, 2, 3, 5 };
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sort" << endl;
    printArr(arr, len);

    quickSort(arr, 0, len);

    cout << "Sorted array" << endl;
    printArr(arr, len);
}