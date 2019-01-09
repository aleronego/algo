#include <iostream>
using namespace std;

void selectionSort(int arr[], int len)
{
    for (int i = 0; i < len; ++i) {
        int min = i;
        for (int j = i; j < len; ++j)
            if (arr[j] < arr[min])
                min = j;

        if (min != i)
            swap(arr[i], arr[min]);
    }
}

int main()
{
    int arr[] = { 4, 7, 6, 9, 8, 1, 2, 3, 5 };
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sort:" << endl;
    for (int i = 0; i < len; ++i)
        cout << arr[i] << " ";

    selectionSort(arr, len);

    cout << endl
         << "After sort:" << endl;
    for (int i = 0; i < len; ++i)
        cout << arr[i] << " ";

    return 0;
}