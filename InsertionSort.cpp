#include <iostream>

using namespace std;

void printArr(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void insertionSort(int arr[], int n)
{
  int temp, j;
  for (int i = 1; i < n; i++)
  {
    temp = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

int main()
{
  int arr[10] = {4, 6, 1, 2, 8, 7, 5, 11, 0, 3};
  int length = sizeof(arr) / sizeof(arr[0]);
  printArr(arr, length);
  insertionSort(arr, length);
  printArr(arr, length);

  return 0;
}