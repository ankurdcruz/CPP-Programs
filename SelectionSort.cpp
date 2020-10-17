#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter the elements of aray: \n";
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    
	for(int i = 0; i < n-1; i++) {
		int idx = i;
		for(int j = i+1; j < n; j++) {
			if(arr[j] < arr[idx]) 
			    idx = j;
		}
		int temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;
	}
	
	cout<<"After sorting: ";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}
