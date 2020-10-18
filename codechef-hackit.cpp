  #include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int temp = n;
	    int i = 0;
	    int N = 0;
	    while(temp!=0){
	        int t = temp%10;
	        N = N + (t-2)*pow(10,i);
	        temp = temp/10;
	        i++;
	    }
	    cout<<N<<endl;
	}
	return 0;
}
