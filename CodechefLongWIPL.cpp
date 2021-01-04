#include <bits/stdc++.h>
using namespace std;
int findMin(int arr[], int n) {
    int sum=0; 
    for (int i=0; i<n; i++)
        sum += arr[i];
 
    bool dp[n+1][sum+1];
 
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
 
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j)
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    }
  
    int diff = INT_MAX;
    for (int j=sum/2; j>=0; j--) {
        if (dp[n][j] == true) {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}
int main() {
	
	int t;
	cin>>t;
	while(t--) {
	    int n,k;
	    cin>>n>>k;
	   
	    int h[n], sum=0;
	    for(int i=0; i<n; i++) {
	        cin>>h[i];
	        sum+=h[i];
	    }
	    if(sum<2*k) {
	        cout<<-1<<endl;
	        return 0;
	    }
		sort(h,h+n);
		sum=0;
		int i=n-1, j=0;
        int a[n];
        bool ans=false;
		while(sum<2*k) {
			sum+=h[i];
            a[j]=h[i];
            j++;
			i--;
		}
        while(ans!=true) {
            
            if((sum-findMin(a,j))/2>=k) {
                ans=true;
                cout<<j<<"\n";
                break;
            }
            else {
                a[j]=h[i];
                sum+=a[j];
                j++;
                i--;
            }
            if(i<0) {
                cout<<-1<<endl;
                break;
            }
        }
	return 0;
}
