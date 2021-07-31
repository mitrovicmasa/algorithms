#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, q;
    cin >> n >> q;

    vector<int> niz(n);
    for(int i=0; i<n; i++)
        cin >> niz[i];
    
    vector<pair<int,int>> parovi(q);
    for(int i=0; i<q; i++) 
        cin >> parovi[i].first >> parovi[i].second;
    //-1 2 2 5 4
    sort(niz.begin(), niz.end());

    for(int i=0; i<q; i++) {
        int a = parovi[i].first;
        int b = parovi[i].second;

        auto it1 = lower_bound(niz.begin(), niz.end(), a);
        auto it2 = upper_bound(niz.begin(), niz.end(), b);
            cout << it2 - it1 << endl;
    }

    return 0;
} 