#include <bits/stdc++.h>

using namespace std;

struct Node{
    string word;
    int count;
    unordered_map<char,Node*> nodes;
};

Node *create_node() {
    Node *new_node = new Node();
    new_node->word = "";
    new_node->count = 0;

    return new_node;
}

void add_word(Node *root, string &word, int i) {
    if(i==(int)word.size()) {
        root->count++;
        root->word = word;
        return ;
    }

    auto iterator = root->nodes.find(word[i]);

    if(iterator == root->nodes.end())
        root->nodes[word[i]] = create_node();
    
    add_word(root->nodes[word[i]], word, i+1);
}

void find_max_occuring_word(Node *root, string &max_word, int &max) {
    if(root->word != "") {
        cout << root->word << " " << max << "\n";
        if(root->count > max) {
            max = root->count;
            max_word = root->word;
        }
    }

    auto begin = root->nodes.begin();
    auto end = root->nodes.end();

    while(begin != end) {
        find_max_occuring_word(begin->second, max_word, max);
        begin++;
    }
}

void free_tree(Node *root) {
    if(root == nullptr)
        return ;

    for(auto &p: root->nodes)
        free_tree(p.second);
    
    delete root;
}

int main() {
    vector<string> words = {"cod", "codecs", "coding", "coder", "coding", "coder", "coding"};
    Node *root = create_node();

    for(string &s: words)
        add_word(root,s,0);
    string max_word = "";
    int max = 0;
    find_max_occuring_word(root, max_word, max);
    cout << max_word << endl;

    free_tree(root);
    return 0;   
}