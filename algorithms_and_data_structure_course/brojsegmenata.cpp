#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;

    cin >> t >> n;  
    vector<int> a(n);

    for(int i=0; i<n; i++)
        cin >> a[i];
    
    unordered_map<int,int> mapica;
    int x;
    // k=3
    //1 2 3 -1 4 niz
    //1 3 6  5 9 prefiksne
    int rezultat = 0;
    int pref = 0;

    for(int i=0; i<n; i++) {
        pref += a[i];
        if(pref <= t)
            rezultat++;
    }

    cout << rezultat << endl;
    return 0;
}  