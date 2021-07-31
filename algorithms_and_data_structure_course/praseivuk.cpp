#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i=0; i<n; i++) { 
        cin >> a[i];
        a[i] = a[i]*a[i];
    }

    sort(a.begin(), a.end());
    int br = 0;
    int l, d;
    for(int i=2; i<n; i++) {
        l=0;
        d=i-1;
        while(l<d) {
            if(a[l]+a[d]==a[i]) {
                br++;
                l++;
            }
            else if(a[l]+a[d] < a[i])
                    l++;
            else d--;
        }
    }

    cout << br << endl;
    return 0;
}