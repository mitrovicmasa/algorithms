#include <bits/stdc++.h>

using namespace std;

#define MAX 100

struct Node {
    int count;
    Node *nodes[2];
};

Node *create_node() {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->count = 0;
    new_node->nodes[0] = new_node->nodes[1] = nullptr;
    
    return new_node;   
}

void add_row(Node *root, int row[MAX], int n, int i, int number) {
    if(i==n) {
        root->count++;

        if(root->count > 1)
            cout << number << endl;
        return ;
    }

    if(root->nodes[row[i]] == nullptr)
        root->nodes[row[i]] = create_node();
    
    add_row(root->nodes[row[i]], row, n, i+1, number);
}

void free_tree(Node *root) {
    if(root == nullptr)
        return;
    
    for(auto &node: root->nodes)
        free_tree(node);
    
    free(root);
}

int main () {
    int matrix[MAX][MAX] = {
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
		{1, 0, 0, 1, 0},
		{0, 0, 1, 1, 0},
		{0, 1, 1, 1, 0}
    };

    int n = 5;

    Node *root = create_node();

    for(int i=0; i<n; i++)
        add_row(root, matrix[i], n, 0, i+1);

    free_tree(root);

    return 0;
}