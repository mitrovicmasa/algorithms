#include <bits/stdc++.h>

using namespace std;

int main () {
    string s;
    cin >> s;
    int br=0;
    stack<char> c;
    for(int i=0; i < s.size(); i++) {
        if(s[i]=='[')
            c.push('[');
        else if(s[i] == '(')
            c.push('(');
        else if(s[i] == '{')
            c.push('{');
        else if(s[i] == ']') {
                if(c.top() == '[')
                    c.pop();
                else br=1;
        }
        else if(s[i] == ')') {
                if(c.top() == '(')
                    c.pop();
                else br=1;
        }
        else if(s[i] == '}') { 
                if(c.top() == '{')
                    c.pop();
                else br=1;
        }
    }
    if(!c.empty())
        br=1;

    if(br==0)
        cout << "da" << endl;
    else cout << "ne" << endl;
    return 0;
}