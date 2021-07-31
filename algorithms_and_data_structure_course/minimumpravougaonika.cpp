#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> a(m);

    for(int i=0; i<m; i++)
        a[i].resize(n);
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }


    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(i==0 && j==0)
                continue;
            else if(i==0)
                a[i][j] = min(a[i][j-1],a[i][j]);
            else if(j==0)
                    a[i][j] = min(a[i-1][j],a[i][j]);
            else
                a[i][j] = min({a[i][j-1], a[i-1][j], a[i][j]});

        } 
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}