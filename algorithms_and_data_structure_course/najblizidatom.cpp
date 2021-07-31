#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> n;
    vector<int> reklame(n);

    for(int i=0; i<n; i++)
        cin >> reklame[i];
    int a;
    
    cin >> m;
    vector<int> sk(m);

    for(int i=0; i<m; i++) {
        cin >> sk[i];
    }

    vector<int> izlaz(m);


    for(int i=0; i<m; i++) {
        auto lb = lower_bound(reklame.begin(), reklame.end(), sk[i]);
        int index = distance(reklame.begin(),lb);
    
        if(abs(reklame[index] - sk[i]) <
            abs(reklame[index - 1] - sk[i]))
            izlaz[i] = index;
        else {
            auto clan = find(reklame.begin(), 
            reklame.end(), reklame[index-1]);
            izlaz[i] = distance(reklame.begin(),clan);
        }
        cout << izlaz[i] << '\n';
    }

    return 0;
}