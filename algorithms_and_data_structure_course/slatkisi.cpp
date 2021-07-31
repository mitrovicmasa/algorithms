#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;

    cin >> n;
    vector<int> cene(n);
    vector<int> pfs(n+1); //prefiksne sume
    for(int i=0; i<n; i++)
        cin >> cene[i];

    for(int i=0; i<n+1; i++) {
        if(i==0)
            pfs[i] = 0;
        else
            pfs[i] = pfs[i-1] + cene[i-1];
    }

    cin >> m;
    vector<pair<int,int>> upiti(m);
    for(int i=0; i<m; i++) {
        cin >> upiti[i].first >> upiti[i].second;
    }

    

    for(int i=0; i<m; i++) {
    
        auto pocetak = next(begin(pfs), upiti[i].first);
        auto kraj = end(pfs);
        auto indikator = upper_bound(pocetak, kraj, pfs[(upiti[i].first)] + upiti[i].second);
        cout << distance(pocetak, indikator) - 1 << '\n';
    }

    return 0;
}