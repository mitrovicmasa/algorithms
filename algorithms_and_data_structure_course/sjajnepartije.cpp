#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int k, p, n;

    cin >> p >> k >> n;
    vector<int> niz(n);

    for(int i=0; i<n; i++) {
        cin >> niz[i];
    }
    int brojac=0;
    int s=0;

    for(int i=0; i<n; i++) {
        if(niz[i] >= p) {
            brojac++;
            if(brojac == k)
                s = 1;
        }
        else brojac = 0;
    }

    (s==1) ? cout << "da" : cout << "ne";
    cout << endl;
    
    return 0;
}