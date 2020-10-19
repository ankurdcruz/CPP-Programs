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

void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main()
{
  int arr[10] = {4, 6, 1, 2, 8, 7, 5, 11, 0, 3};
  int length = sizeof(arr) / sizeof(arr[0]);
  printArr(arr, length);
  bubbleSort(arr, length);
  printArr(arr, length);

  return 0;
}