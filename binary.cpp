#include <iostream>
using namespace std;

int binary_search(int num, int arr[])
{
    int l = 0;
    int h = 100;
    int it = 0;
    while (l <= h) {
        ++it;
        int mid = (h + l) / 2;
        cout << "it: " << it << " mid: " << mid << endl;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] < num)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[101];
    for (int i = 0; i < 101; ++i) {
        arr[i] = i;
    }
    cout << endl
         << "Your number: (0-100) ";
    int num = 0;
    cin >> num;
    if (num >= 0 && num <= 100) {
        cout << binary_search(num, arr) << " found" << endl;
    } else {
        cout << "Wrong number" << endl;
    }
}