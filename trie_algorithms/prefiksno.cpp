#include <bits/stdc++.h>

using namespace std;

#define CHAR_SIZE 128

struct Node {
    bool is_leaf;
    Node *nodes[CHAR_SIZE];
};

Node *create_node() {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->is_leaf = false;

    for(int i=0; i< CHAR_SIZE; i++)
        new_node->nodes[i] = nullptr;
    
    return new_node;
}

void add_word(Node *root, string &word) {
    int n = word.length();

    for(int i=0; i<n; i++) {
        if(root->nodes[(int)word[i]]==nullptr)
            root->nodes[(int)word[i]] = create_node();
        root = root->nodes[(int)word[i]];
    }
    root->is_leaf = true;
}

bool find_word(Node *root, string &word) {
    if(root==nullptr)
        return false;
    int n = word.length();

    for(int i=0; i<n; i++) {
        root = root->nodes[(int)word[i]];
        if(root == nullptr)
            return false;
    }

    return root->is_leaf;
}

void free_tree(Node *root) {
    if(root == nullptr)
        return ;
    for(auto &node: root->nodes)
        free_tree(node);
    free(root);
}

int main () {
    vector<string> words = {"cod", "coder", "coding", "codex"};
    Node *root = create_node();

    for(string &s: words)
        add_word(root, s);
    
    string s = "coder";

    cout << boolalpha << find_word(root, s) << endl;
    free_tree(root);

    return 0;
}