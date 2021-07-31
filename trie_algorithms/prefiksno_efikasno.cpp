#include <bits/stdc++.h>

using namespace std;

struct Node {
    bool is_leaf;
    unordered_map<char, Node*> nodes;
};

Node *create_node() {
    Node *new_node = new Node();
    new_node->is_leaf = false;

    return new_node;
}

void add_word(Node *root, string &word, int i) {
    if (i == (int)word.size()) {
        root->is_leaf = true;
        return;
    }

    auto iterator = root->nodes.find(word[i]);
    if(iterator == root->nodes.end())
        root->nodes[word[i]] = create_node();
    
    add_word(root->nodes[word[i]], word, i+1);
}

bool find_word(Node *root, string &word, int i) {
    if(i==(int)word.size()) {
        return root->is_leaf;
    }

    auto iterator = root->nodes.find(word[i]);

    if(iterator == root->nodes.end())
        return false;
    
    return find_word(root->nodes[word[i]], word, i+1);
}

void free_tree(Node *root) {
    if(root = nullptr)
        return;

    for(auto &p: root->nodes)
        free_tree(p.second);

    delete root;
}

int main () {
    vector<string> words = {"cod", "coder", "coding", "codecs"};

    Node *root = create_node();

    for(string &s: words)
        add_word(root, s, 0);
    string s = "code";

    cout << boolalpha << find_word(root, s, 0) << endl;

    return 0;
}