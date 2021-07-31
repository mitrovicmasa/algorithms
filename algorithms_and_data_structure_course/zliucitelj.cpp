#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;

    // zelim da nadjem sume tako da
    // budu najvece
    // pa trazim najmanju od njih.. 
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) 
        cin >> a[i];
    
    sort(a.begin(), a.end());
    int max_zbir = a[0] + a[n-1];
    for(int i=1; i < n/2; i++) {
        if( a[i] + a[n-i-1] > max_zbir)
            max_zbir = a[i] + a[n-i-1];
    }

    cout << max_zbir - 1 << endl;

    return 0;
}