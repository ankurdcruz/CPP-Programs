#include <bits/stdc++.h>

using namespace std;

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (arr[l] > arr[i] && l < n)
    largest = l;

  if (arr[r] > arr[i] && r < n)
    largest = r;

  if (largest != i)
  {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n)
{

  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  for (int i = n - 1; i > 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main()
{
  int n = 100;
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    arr[i] = (rand() % 100);
  }

  clock_t tic, tok;

  tic = start();
  heapSort(arr, n);
  toc = start();

  double time_taken = double(tok - tic) / CLOCKS_PER_SEC);
  cout << "Time taken: " << fixed << time_taken << "s";

  return 0;
}