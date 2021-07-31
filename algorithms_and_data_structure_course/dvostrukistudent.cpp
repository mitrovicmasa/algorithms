#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<pair<string,string>> studenti;

    string s,t;
    int i =0;

    while(cin >> s) {
        cin >> t;
        studenti.push_back({s,t});
        i++;
    }

    sort(studenti.begin(), studenti.end());

    for(int j=0; j<i-1; j++) {
        if(studenti[j].first == studenti[j+1].first && 
           studenti[j].second == studenti[j+1].second) {
               cout << studenti[j].first << ' ' << studenti[j].second << endl;
               break;
           }
    }

    return 0;
}