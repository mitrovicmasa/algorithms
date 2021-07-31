#include <bits/stdc++.h>

using namespace std;

struct Node {
    bool is_leaf;
    Node *nodes[2];
};

Node *create_node() {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->is_leaf = false;
    new_node->nodes[0] = new_node->nodes[1] = nullptr;

    return new_node;
}

int value(string &binary) {
    int n = binary.size();
    int value = 0;

    for(int i=0, j=n-1; i<n; i++, j--)
        value += pow(2,i)*(binary[j] - '0');

    return value;
}

void add_number(Node *root, string &number, int i) {
    if(i == (int)number.size()) {
        root->is_leaf = true;
        return ;
    }

    if(root->nodes[number[i]-'0'] == nullptr)
        root->nodes[number[i] - '0'] = create_node();
    
    add_number(root->nodes[number[i]-'0'], number, i+1);
}
void find_XOR(Node *root, string &XOR, string &number, int i) {
    if(root->is_leaf) {
        return ;
    }

    int digit = number[i] - '0';

    if(root->nodes[abs(digit - 1)]) {
        XOR += '1';
        find_XOR(root->nodes[abs(digit-1)], XOR, number, i+1);
    }
    else {
        XOR += '0';
        find_XOR(root->nodes[digit], XOR, number, i+1);
    }
}

void free_tree(Node *root) {
    if(root == nullptr)
        return ;
    
    for(auto &node: root->nodes)
        free_tree(node);

    free(root);
}


int main() {
    vector<string> numbers = {"101", "000", "011"};

    int max = 0;

    string max_XOR;
    string XOR;

    Node *root = create_node();

    for(string &s: numbers) {
        XOR = "";
        add_number(root, s, 0);
        find_XOR(root, XOR, s, 0);

        if(value(XOR) > max) {
            max = value(XOR);
            max_XOR = XOR;
        }
    }

    cout << max_XOR << endl;

    return 0;
}