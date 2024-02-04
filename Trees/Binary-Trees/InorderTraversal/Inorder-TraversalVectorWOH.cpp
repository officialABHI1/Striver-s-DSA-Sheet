 /*
    In this approach we do the Inorder Traversal for tree

            5
        10    20
      11  13

      without any helper function and creating a new vector with each fun call

      Time Complexity:  O(N^2)
      Space Complexity: O(depth) == O(N) -in worst Case - Skewed Tree 

 */
 
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<int> ans, left, right;

        left = inorderTraversal(root->left);
        right = inorderTraversal(root->right);

        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root->val);
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
    vector<int> inorder = s.inorderTraversal(root);

    // Print the inorder traversal
    cout << "Inorder Traversal: ";
    for (int i : inorder) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
