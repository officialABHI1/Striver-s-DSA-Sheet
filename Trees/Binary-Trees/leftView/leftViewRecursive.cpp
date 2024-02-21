#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

vector<int> leftView(Node *root) {
    
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        bool firstNode = true;

        while (sz--) {
            Node *curr = q.front();
            q.pop();

            if (firstNode) {
                ans.push_back(curr->data);
                firstNode = false;
            }

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }
    }

    return ans;
}


int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Call the leftView function on our sample tree
    auto result = leftView(root);

    // Print the results
    for (const auto& num : result) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    delete root;
    return 0;
}