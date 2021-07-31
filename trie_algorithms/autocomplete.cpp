#include <bits/stdc++.h>

using namespace std;

struct Node {
    bool is_leaf;
    string word;
    unordered_map<char, Node *> nodes;
};

Node *create_node() {
    Node *new_node = new Node();
    new_node->is_leaf = false;
    new_node->word = "";
    return new_node;
}

void add_word(Node *root, string &word, int i) {
    if(i==(int)word.size()) {
        root->word = word;
        root->is_leaf = true;
        return ;
    }

    auto iterator = root->nodes.find(word[i]);

    if(iterator == root->nodes.end())
        root->nodes[word[i]] = create_node();
    
    add_word(root->nodes[word[i]], word, i+1);
}

Node *autocomplete(Node *root, string &prefix, int i) {
    if(i==prefix.size())
        return root;
    
    auto iterator = root->nodes.find(prefix[i]);

    if(iterator == root->nodes.end())
        return nullptr;
    
    return autocomplete(root->nodes[prefix[i]], prefix, i+1);
}

void print(Node *root) {
    if(root->is_leaf)
        cout << root->word << endl;
    
    auto begin = root->nodes.begin();
    auto end = root->nodes.end();

    while(begin != end) {
        print(begin->second);
        begin++;
    }
}

void free_tree (Node *root) {
    if(root == nullptr)
        return ;
    
    for(auto &p: root->nodes)
        free_tree(p.second);
    
    delete root;
}

int main() {
    vector<string> words = {"code", "coder", "codecs", "coding", "cod"};
    Node *root = create_node();

    string prefix = "code";

    for(string &s: words)
        add_word(root, s, 0);
    
    Node *tmp = autocomplete(root, prefix, 0);

    if(tmp != nullptr)
        print(tmp);
    else {
        cout << "Nema!" << endl;
    }
    free_tree(root);

    return 0;
}