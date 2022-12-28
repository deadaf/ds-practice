#include <iostream>

using namespace std;

int partition(int *arr, int s, int e)
{
    int pivot = arr[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;

    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {3, 7, 8, 1, 9, 9, 13, 11, 78, 45, 67};
    int len = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, len - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    // result: 1 3 7 8 9 9 11 13 45 67 78

    return 0;
}