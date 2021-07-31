#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    while(n>1) {
        n--;
        if(a[n]==a[n-1]) {
            cout << a[n];
            break;
        }
    }
    
    return 0;
}