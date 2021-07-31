#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, n;
    cin >> k >> n;

    string nesto;
    map<string, int> ljudi;
    int br=0;

    for(int i=0; i<n; i++) {
        cin >> nesto;
        if(ljudi.find(nesto)!=ljudi.end()) {
            ljudi[nesto]++;
            if(ljudi[nesto] == k)
                br++;
        }
        else {
            ljudi[nesto]=1;
        } 
        cout << br << endl;
    }

    return 0;
}