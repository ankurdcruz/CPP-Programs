#include<bits/stdc++.h>
using namespace std;

int matOrder(int array[], int n){

   int s[n][n];

   for (int i=1; i<n; i++) 
      s[i][i] = 0; 
    
    for (int length=2; length<n; length++){ 
         for (int i=1; i<n-length+1; i++){
            int j = i+length-1;
            s[i][j] = INT_MAX; 
            for (int k=i; k<=j-1; k++){
               
               int q = s[i][k] + s[k+1][j] + array[i-1]*array[k]*array[j];
               if (q < s[i][j])
                  s[i][j] = q;
            }
      }
   }
   return s[1][n-1];
}
int main(){
   int arr[] = {1, 2, 3, 4};
   int size = 4;
   cout << "Minimum number of matrix multiplications: "<<matOrder(arr, size);
}
