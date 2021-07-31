#include <bits/stdc++.h>

using namespace std;

bool prolazak(vector<vector<char>> a, int i, int j) {
    if((i == a.size()-1) && (j==a[i].size()-1)) {
        if( a[i][j] == '.')
            return true;
        else return false;
    }
    else {
        if(a[i][j] == 'x')
            return false;
        else {
            a[i][j] = 'x';
            bool x1=false, x2=false, x3=false, x4= false;
            if(j < a[i].size()-1)
                x1=prolazak(a, i, j+1);
            if(i < a.size()-1)
                x2=prolazak(a, i+1, j);
            if(i > 0)
                x3=prolazak(a, i-1, j);
            if(j > 0)
                x4=prolazak(a, i, j-1);

            return x1 || x2 || x3 || x4;
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> matrica;
    matrica.resize(m);
    for(int i=0; i<m; i++)
        matrica[i].resize(n);
 
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++) {
            cin >> matrica[i][j];
        }

    if(prolazak(matrica, 0, 0))
        cout << "da" << endl;
    else 
        cout << "ne" << endl;
    
    return 0;
}