#include <algorithm>
#include <iostream>

using namespace std;

int modval;

bool myFunc(int left, int right) {
    if (left % modval < right % modval) return true;
    if (left % modval == right % modval && left < right) return true;
    return false;
}

void StayHomeTask(int arr[], int n, int k)
{
    modval = k;
    sort(arr, arr+n, myFunc);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}