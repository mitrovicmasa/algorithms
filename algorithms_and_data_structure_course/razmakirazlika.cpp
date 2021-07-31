#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> k >> n;
    deque<int> a;
    int tmp=k;
    int nesto, br=0;
    for(int i=0; i<n; i++) {
        cin >> nesto;
        a.push_front(nesto);
        if(tmp == 0) {
            if(a[0]==a[k] + k)
                br++;
            a.pop_back();
            tmp = 1;
        }
        tmp--;
    }
    

    cout << br << endl;

    return 0;
}