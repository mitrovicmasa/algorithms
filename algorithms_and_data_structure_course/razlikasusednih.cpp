#include <bits/stdc++.h>
using namespace std;

void dodajcifre(int cifra, int n, int k, int i, string s) {
    s+=to_string(cifra);
    i++;
    if(i>=n) {
        if(s.size() != n)
            return;
        long long x = stoll(s);
        cout << x << endl;
        s = "";
        return ;
    }
    else {
    if(k==0) {
        dodajcifre(cifra, n, k, i, s);
    }
    else if(cifra < k && cifra <= 9-k)
        dodajcifre(cifra+k, n, k, i, s); 
    else if(cifra <= 9-k) {
        dodajcifre(cifra-k, n, k, i, s);
        dodajcifre(cifra+k, n, k, i, s);
    }
    else dodajcifre(cifra-k, n, k, i, s);
    }
}

int main() {

    int k, n;
    string s="";
    cin >> n >> k;

    
    for(int i=1; i<10; i++)
        dodajcifre(i, n, k, 0, s);
   
    return 0;
}