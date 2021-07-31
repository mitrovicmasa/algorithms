#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;

    cin >> n >> k;

    int l, d;

    if(n%k==0) {
        l = n;
        d = n;
    } else {
        d = n - n%k;
        l = n + k - n%k;
    }
    
    cout << d << endl << l << endl;


    return 0;
}