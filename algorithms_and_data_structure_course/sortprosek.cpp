#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    return a[n-1] > b[m-1];
}

int main() {
    int u, o;

    cin >> u >> o;

    vector< vector<int> > ocene(u);

    for(int i=0; i<u; i++)
        ocene[i].resize(o + 1);
    
    for(int i=0; i<u; i++) {
        ocene[i][o]=0;
        for(int j=0; j<o; j++) {
            cin >> ocene[i][j];
            ocene[i][o] += ocene[i][j];
        }
    }

    stable_sort(ocene.begin(), ocene.end(), cmp);

    for(int i=0; i<u; i++) {
        for(int j=0; j<o; j++)
            cout << ocene[i][j] << ' ';
        cout << endl;
    }

    return 0;
}