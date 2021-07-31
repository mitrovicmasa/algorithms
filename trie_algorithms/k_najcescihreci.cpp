#include <bits/stdc++.h>

using namespace std;

struct Node {
    string word;
    int count;
    unordered_map<char, Node *> nodes;
};

Node *create_node() {
    Node *new_node = new Node();
    new_node->word = "";
    new_node->count = 0;

    return new_node;
}

void add_word(Node *root, string &word, int i) {
    if(i == (int)word.size()) {
        root->count++;
        root->word = word;
        return ;
    }

    auto iterator = root->nodes.find(word[i]);

    if(iterator == root->nodes.end())
        root->nodes[word[i]] = create_node();

    add_word(root->nodes[word[i]], word, i+1);
}

struct comparator {
    bool operator()(Node *n1, Node *n2) {
        return n1->count < n2->count;
    }
};

void put_words_into_heap (Node *root, priority_queue<Node *, vector<Node *>, comparator> &heap) {
    if(root->word != "") {
        heap.push(root);
    }

    auto begin = root->nodes.begin();
    auto end = root->nodes.end();

    while(begin != end) {
        put_words_into_heap(begin->second, heap);
        begin++;
    }
}

void free_tree(Node *root) {
    if(root == nullptr)
        return ;

    for(auto &p: root->nodes) {
        free_tree(p.second);
    }
    delete root;
}

int main () {
    vector<string> words = {"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codec", "codecs", "codependence", "codex", "codify",
		"codependents", "codes", "code", "coder", "codesign", "codec",
		"codeveloper", "codrive", "codec", "codecs", "codiscovered"};
    Node *root = create_node();

    for(string &s: words) {
        add_word(root, s, 0);
    }

    priority_queue<Node *, vector<Node *>, comparator> heap;

    put_words_into_heap(root, heap);

    int k=3;

    Node *tmp;

    while(k && heap.size()) {
        tmp = heap.top();
        heap.pop();

        cout << tmp->word << " occurs " << tmp->count << endl;
        k--;
    }
    
    free_tree(root);

    return 0;
}