#include <bits/stdc++.h>

using namespace std;

struct Node {
    string word;
    map<char,Node*> nodes;
};

Node *create_node() {
    Node *new_node = new Node();
    new_node->word = "";
    return new_node;
}

void add_word(Node *root, string &word, int i) {
    if(i==(int)word.size()) {
        root->word = word;
        return ;
    }

    auto iterator = root->nodes.find(word[i]);

    if(iterator == root->nodes.end())
        root->nodes[word[i]] = create_node();

    add_word(root->nodes[word[i]], word, i+1);
}

void lexicographic(Node *root) {
    if(root->word != "")
        cout << root->word << endl;
    
    auto begin = root->nodes.begin();
    auto end = root->nodes.end();

    while(begin != end) {
        lexicographic(begin->second);
        begin++;
    }
}

void free_tree(Node *root) {
    if(root == nullptr)
        return;

    for(auto &p: root->nodes)
        free_tree(p.second);

    delete root;
}

int main() {
    vector<string> words = {"cod", "coder", "coding", "codecs"};
    Node *root = create_node();

    for(string &s: words) {
        add_word(root, s, 0);
    }
    lexicographic(root);
    
    free_tree(root);
    return 0;
}