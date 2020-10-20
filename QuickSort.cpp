#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main()
{
    clock_t tic, toc;
    int n = 10000;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    tic = clock();
    quickSort(arr, 0, n - 1);
    toc = clock();

    double time_taken = double(toc - tic) / double(CLOCKS_PER_SEC);

    cout << "Worst time taken: " << fixed << time_taken << "s" << endl;

    return 0;
}