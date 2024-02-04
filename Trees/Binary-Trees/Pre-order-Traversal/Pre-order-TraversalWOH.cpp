 #include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<int> ans, left, right;

        left =  preorderTraversal(root->left);
        right = preorderTraversal(root->right);

        ans.push_back(root->val);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};

int main() {
    // Construct the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create a Solution object
    Solution s;
    // Get the inorder traversal
    vector<int> preorder = s.preorderTraversal(root);

    // Print the inorder traversal
    cout << "Preorder Traversal: ";
    for (int i : preorder) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
