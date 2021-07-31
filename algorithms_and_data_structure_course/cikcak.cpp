#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >>  a[i];

    sort(a.begin(), a.end());
    vector<int> b(n);
    int j = 0;
    for(int i=0; i<n; i++) {
        if(i%2==0) {
            b[j] = a[i];
            j++;
        }
    }
    for(int i=n-1; i>0; i--) {
        if(i%2!=0) {
            b[j] = a[i];
            j++;
        }
    }
    
    for(int i=0; i<n; i++)
        cout << b[i] << endl;
    
    return 0;
}