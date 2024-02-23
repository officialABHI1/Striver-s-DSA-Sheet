#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        else if (p != NULL && q == NULL || p == NULL && q != NULL) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    // Create two binary trees
    TreeNode* p = new TreeNode(1);
    p->left = NULL;
    p->right = new TreeNode(1);

    TreeNode* q = new TreeNode(1);
    q->left = NULL;
    q->right = new TreeNode(1);

    // Check if the trees are identical
    Solution solution;
    bool result = solution.isSameTree(p, q);

    // Print the result
    if (result) {
        cout << "The trees are identical." << endl;
    }
    else {
        cout << "The trees are not identical." << endl;
    }

    // Free memory
    delete p->right;
    delete p;
    delete q->right;
    delete q;

    return 0;
}