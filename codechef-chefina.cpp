#include <bits/stdc++.h>
using namespace std;

bool result(int m, int n) {

    if((m*(m+1)/2) == (n(n+1)/2) - (m*(m+1)/2))
        return true;
    else
        return false;
    
}

int main() {

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int count = 0;
        for(int i=1; i<n; i++) {
            bool r = result(i,n);
            if(r == true)
                count++;
        }
        cout<<count;
    }
    
}
