#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<long long> S;

    long long n; 
    cin >> n;
    char c;
    long long x, y;
    vector<long long> govno;

    for(long i=0; i<n; i++) {
        cin >> c;
        if(c=='t') {
            cin >> x;
            S.insert(x);
        }
        else if(c=='i') {
            cin >> x >> y;
            if(S.size()==0) {
                govno.push_back(0);
            }
            else {
                auto a= S.lower_bound(x);
                auto b= S.lower_bound(y);
                if(b == S.end())
                    b = prev(b);
                if(a == S.end())
                    a = prev(a);
                govno.push_back((*b) - (*a));
            }
        }
    }

    for(long i=0; i<govno.size(); i++) {
        cout << govno[i] << endl;
    }

    return 0;
}