#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    int zbir=0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        zbir+= a[i];
    }

    vector<int> b(n);
    int trenutni=0;
    for(int i=0; i<n; i++) {
        trenutni += a[i];
        b[i] = abs(zbir - 2*trenutni);
    }
    int min=b[0];
    int mini=0;
    for(int i=1; i<n; i++) {
        if(b[i]<min) {
            min = b[i];
            mini = i;
        }
    }

    cout << mini << endl;
    
    return 0;
}