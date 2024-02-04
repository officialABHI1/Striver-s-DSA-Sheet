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
    vector<int> postOrderTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<int> ans, left, right;

        left =  postOrderTraversal(root->left);
        right = postOrderTraversal(root->right);

        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), right.begin(), right.end());
        ans.push_back(root->val);

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
    vector<int> postOrder = s.postOrderTraversal(root);

    // Print the inorder traversal
    cout << "Postorder Traversal: ";
    for (int i : postOrder) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
