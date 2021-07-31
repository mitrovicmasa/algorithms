#include <bits/stdc++.h>

using namespace std;

int main () {
    int k, n;
    cin >> k >> n;
    
    vector<double> a(n);
    vector<double> pf(n);
    double max = 0;
    int maxi = 0;

    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(i==0)
            pf[i] = a[i];
        else pf[i] = pf[i-1] + a[i];

        if(i == k-1) {
            double prosek = pf[i]/3;
            if(prosek > max) {
                max = prosek;
                maxi = i-k+1;
            }
        }
        if(i>k-1) {
            double prosek = (pf[i]- pf[i-k])/3;
            if(prosek > max) {
                max = prosek;
                maxi = i-k+1;
            }
        }
    }
    cout << maxi << endl;

    return 0;
}